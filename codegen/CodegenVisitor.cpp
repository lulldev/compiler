#include "CodegenVisitor.h"
#include <boost/format.hpp>

namespace
{
ExpressionType GetExpressionTypeOfIntegerLLVMType(llvm::Type* type)
{
	assert(type->isIntegerTy());
	switch (type->getIntegerBitWidth())
	{
	case 32:
		return ExpressionType::Int;
	case 1:
		return ExpressionType::Bool;
	default:
		throw std::invalid_argument("unsupported integer bit width");
	}
}

ExpressionType ToExpressionType(llvm::Type* type)
{
	if (type->isIntegerTy())
	{
		return GetExpressionTypeOfIntegerLLVMType(type);
	}
	if (type->isDoubleTy())
	{
		return ExpressionType::Float;
	}
	// String
	if (type->isPointerTy())
	{
		llvm::Type* ptrElementType = type->getPointerElementType();
		if (ptrElementType->getTypeID() == llvm::Type::IntegerTyID && ptrElementType->getIntegerBitWidth() == 8)
		{
			return ExpressionType::String;
		}
	}
	throw std::invalid_argument("unsupported llvm type");
}

llvm::Type* ToLLVMType(ExpressionType type, llvm::LLVMContext& context)
{
	switch (type)
	{
	case ExpressionType::Int:
		return llvm::Type::getInt32Ty(context);
	case ExpressionType::Float:
		return llvm::Type::getDoubleTy(context);
	case ExpressionType::Bool:
		return llvm::Type::getInt1Ty(context);
	case ExpressionType::String:
		return llvm::Type::getInt8PtrTy(context);
	default:
		throw std::logic_error("can't convert string ast literal to llvm type");
	}
}

llvm::Value* ConvertToIntegerValue(
	llvm::Value* value,
	llvm::LLVMContext& llvmContext,
	llvm::IRBuilder<>& builder)
{
	const ExpressionType type = ToExpressionType(value->getType());

	switch (type)
	{
	case ExpressionType::Int:
		return value;
	case ExpressionType::Float:
		return builder.CreateFPToUI(value, llvm::Type::getInt32Ty(llvmContext), "icasttmp");
	case ExpressionType::Bool:
		return builder.CreateIntCast(value, llvm::Type::getInt32Ty(llvmContext), false, "icasttmp");
	case ExpressionType::String:
		throw std::runtime_error("can't cast string to integer");
	}

	assert(false);
	throw std::logic_error("ConvertToIntValue() - value type is unknown");
}

llvm::Value* ConvertToFloatValue(
	llvm::Value* value,
	llvm::LLVMContext& llvmContext,
	llvm::IRBuilder<>& builder)
{
	const ExpressionType type = ToExpressionType(value->getType());

	switch (type)
	{
	case ExpressionType::Int:
	case ExpressionType::Bool:
		return builder.CreateUIToFP(value, llvm::Type::getDoubleTy(llvmContext), "fcasttmp");
	case ExpressionType::Float:
		return value;
	case ExpressionType::String:
		throw std::runtime_error("can't cast string to float");
	}

	assert(false);
	throw std::logic_error("ConvertToIntValue() - value type is unknown");
}

llvm::Value* ConvertToBooleanValue(
	llvm::Value* value,
	llvm::LLVMContext& llvmContext,
	llvm::IRBuilder<>& builder)
{
	const ExpressionType expressionType = ToExpressionType(value->getType());

	switch (expressionType)
	{
	case ExpressionType::Int:
		return builder.CreateNot(builder.CreateICmpEQ(
			value, llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvmContext), uint64_t(0)), "bcasttmp"));
	case ExpressionType::Float:
		return builder.CreateNot(builder.CreateFCmpOEQ(
			value, llvm::ConstantFP::get(llvm::Type::getDoubleTy(llvmContext), 0.0), "fcmptmp"), "nottmp");
	case ExpressionType::Bool:
		return value;
	case ExpressionType::String:
		throw std::runtime_error("can't cast string to bool");
	}

	assert(false);
	throw std::logic_error("ConvertToBooleanValue() - undefined ast expression type");
}

llvm::Value* CastValue(
	llvm::Value* value,
	ExpressionType type,
	llvm::LLVMContext& llvmContext,
	llvm::IRBuilder<> & builder)
{
	switch (type)
	{
	case ExpressionType::Int:
		return ConvertToIntegerValue(value, llvmContext, builder);
	case ExpressionType::Float:
		return ConvertToFloatValue(value, llvmContext, builder);
	case ExpressionType::Bool:
		return ConvertToBooleanValue(value, llvmContext, builder);
	}
	return nullptr;
}

llvm::Value* CreateIntegerBinaryExpression(
	llvm::Value* left,
	llvm::Value* right,
	BinaryExpressionAST::Operator operation,
	llvm::LLVMContext& llvmContext,
	llvm::IRBuilder<> & builder)
{
	assert(ToExpressionType(left->getType()) == ToExpressionType(right->getType()));
	assert(ToExpressionType(left->getType()) == ExpressionType::Int);

	switch (operation)
	{
	case BinaryExpressionAST::Or:
		return builder.CreateOr(
			ConvertToBooleanValue(left, llvmContext, builder), 
			ConvertToBooleanValue(right, llvmContext, builder), "ortmp");
	case BinaryExpressionAST::And:
		return builder.CreateAnd(
			ConvertToBooleanValue(left, llvmContext, builder),
			ConvertToBooleanValue(right, llvmContext, builder), "andtmp");
	case BinaryExpressionAST::Equals:
		return builder.CreateICmpEQ(left, right, "eqtmp");
	case BinaryExpressionAST::Less:
		return builder.CreateICmpSLT(left, right, "lttmp");
	case BinaryExpressionAST::Plus:
		return builder.CreateAdd(left, right, "addtmp");
	case BinaryExpressionAST::Minus:
		return builder.CreateSub(left, right, "subtmp");
	case BinaryExpressionAST::Mul:
		return builder.CreateMul(left, right, "multmp");
	case BinaryExpressionAST::Div:
		return builder.CreateSDiv(left, right, "divtmp");
	case BinaryExpressionAST::Mod:
		return builder.CreateSRem(left, right, "modtmp");
	}

	assert(false);
	throw std::logic_error("CreateIntBinaryExpression() - undefined binary expression ast operator");
}

llvm::Value* CreateFloatBinaryExpression(
	llvm::Value* left,
	llvm::Value* right,
	BinaryExpressionAST::Operator operation,
	llvm::LLVMContext& llvmContext,
	llvm::IRBuilder<> & builder)
{
	assert(ToExpressionType(left->getType()) == ToExpressionType(right->getType()));
	assert(ToExpressionType(left->getType()) == ExpressionType::Float);

	switch (operation)
	{
	case BinaryExpressionAST::Or:
		return builder.CreateOr(
			ConvertToBooleanValue(left, llvmContext, builder),
			ConvertToBooleanValue(right, llvmContext, builder), "ortmp");
	case BinaryExpressionAST::And:
		return builder.CreateAnd(
			ConvertToBooleanValue(left, llvmContext, builder),
			ConvertToBooleanValue(right, llvmContext, builder), "andtmp");
	case BinaryExpressionAST::Equals:
		return builder.CreateFCmpOEQ(left, right, "eqtmp");
	case BinaryExpressionAST::Less:
		return builder.CreateFCmpOLT(left, right, "lttmp");
	case BinaryExpressionAST::Plus:
		return builder.CreateFAdd(left, right, "addtmp");
	case BinaryExpressionAST::Minus:
		return builder.CreateFSub(left, right, "subtmp");
	case BinaryExpressionAST::Mul:
		return builder.CreateFMul(left, right, "multmp");
	case BinaryExpressionAST::Div:
		return builder.CreateFDiv(left, right, "divtmp");
	case BinaryExpressionAST::Mod:
		return builder.CreateFRem(left, right, "modtmp");
	}

	assert(false);
	throw std::logic_error("CreateFloatBinaryExpression() - undefined binary expression ast operator");
}

llvm::Value* CreateBooleanBinaryExpression(
	llvm::Value* left,
	llvm::Value* right,
	BinaryExpressionAST::Operator operation,
	llvm::LLVMContext& llvmContext,
	llvm::IRBuilder<> & builder)
{
	assert(ToExpressionType(left->getType()) == ToExpressionType(right->getType()));
	assert(ToExpressionType(left->getType()) == ExpressionType::Bool);
	(void)llvmContext;

	switch (operation)
	{
	case BinaryExpressionAST::Or:
		return builder.CreateOr(left, right, "bortmp");
	case BinaryExpressionAST::And:
		return builder.CreateAnd(left, right, "bandtmp");
	case BinaryExpressionAST::Equals:
		return builder.CreateICmpEQ(left, right, "beqtmp");
	case BinaryExpressionAST::Less:
		return builder.CreateICmpSLT(left, right, "blttmp");
	case BinaryExpressionAST::Plus:
	case BinaryExpressionAST::Minus:
	case BinaryExpressionAST::Mul:
	case BinaryExpressionAST::Div:
	case BinaryExpressionAST::Mod:
		throw std::runtime_error("can't perform codegen for operator '" + ToString(operation) + "' on booleans");
	}

	assert(false);
	throw std::logic_error("CreateBooleanBinaryExpression() - undefined binary expression ast operator");
}

llvm::Value* CreateNegativeValue(llvm::Value* value, llvm::IRBuilder<> & builder)
{
	const ExpressionType type = ToExpressionType(value->getType());
	switch (ToExpressionType(value->getType()))
	{
	case ExpressionType::Int:
		return builder.CreateNeg(value, "negtmp");
	case ExpressionType::Float:
		return builder.CreateFNeg(value, "fnegtmp");
	case ExpressionType::Bool:
		return builder.CreateNeg(value, "bnegtmp");
	case ExpressionType::String:
	default:
		throw std::runtime_error("can't create negative value of " + ToString(type));
	}
}

llvm::Value* CreateValueNegation(llvm::Value* value, llvm::LLVMContext& llvmContext, llvm::IRBuilder<> & builder)
{
	return builder.CreateNot(ConvertToBooleanValue(value, llvmContext, builder));
}

llvm::Value* CreateDefaultValue(ExpressionType type, llvm::LLVMContext& llvmContext, llvm::IRBuilder<> & builder)
{
	switch (type)
	{
	case ExpressionType::Int:
		return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvmContext), llvm::APInt(32, uint64_t(0), true));
	case ExpressionType::Float:
		return llvm::ConstantFP::get(llvm::Type::getDoubleTy(llvmContext), 0.0);
	case ExpressionType::Bool:
		return llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvmContext), uint64_t(0));
	case ExpressionType::String:
	{
		llvm::Type* i8 = llvm::Type::getInt8Ty(llvmContext);
		llvm::ArrayType* arrayType = llvm::ArrayType::get(i8, 1);
		llvm::AllocaInst* allocaInst = builder.CreateAlloca(arrayType, nullptr, "str_alloc");

		std::vector<llvm::Constant*> constants = { llvm::ConstantInt::get(llvm::Type::getInt8Ty(llvmContext), uint64_t(0)) };
		llvm::Constant* arr = llvm::ConstantArray::get(arrayType, constants);

		llvm::StoreInst* storeInst = builder.CreateStore(arr, allocaInst);
		(void)storeInst;

		return builder.CreateBitCast(allocaInst, llvm::Type::getInt8PtrTy(llvmContext), "str_to_i8_ptr");
	}
	default:
		assert(false);
		throw std::logic_error("can't emit code for undefined ast expression type");
	}
}

class ContextScopeHelper
{
public:
	explicit ContextScopeHelper(CodegenContext& context)
		: m_context(context)
	{
		m_context.PushScope();
	}

	~ContextScopeHelper()
	{
		m_context.PopScope();
	}

private:
	CodegenContext& m_context;
};
}

// Expression codegen visitor
ExpressionCodegen::ExpressionCodegen(CodegenContext& context)
	: m_context(context)
	, m_stack()
{
}

llvm::Value* ExpressionCodegen::Visit(const IExpressionAST& node)
{
	node.Accept(*this);
	if (!m_stack.empty())
	{
		llvm::Value* value = m_stack.back();
		m_stack.pop_back();
		return value;
	}
	throw std::logic_error("internal error while generating code for expression");
}

void ExpressionCodegen::Visit(const BinaryExpressionAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::Value* left = Visit(node.GetLeft());
	llvm::Value* right = Visit(node.GetRight());

	if (ToExpressionType(left->getType()) != ToExpressionType(right->getType()))
	{
		const auto castType = GetPreferredType(
			ToExpressionType(left->getType()),
			ToExpressionType(right->getType()));

		if (!castType)
		{
			const auto fmt = boost::format("can't codegen operator '%1%' on operands with types '%2%' and '%3%'")
				% ToString(node.GetOperator())
				% ToString(ToExpressionType(left->getType()))
				% ToString(ToExpressionType(right->getType()));
			throw std::runtime_error(fmt.str());
		}

		switch (*castType)
		{
		case ExpressionType::Int:
			left = ConvertToIntegerValue(left, llvmContext, builder);
			right = ConvertToIntegerValue(right, llvmContext, builder);
			break;
		case ExpressionType::Float:
			left = ConvertToFloatValue(left, llvmContext, builder);
			right = ConvertToFloatValue(right, llvmContext, builder);
			break;
		case ExpressionType::Bool:
			left = ConvertToBooleanValue(left, llvmContext, builder);
			right = ConvertToBooleanValue(right, llvmContext, builder);
			break;
		case ExpressionType::String:
			throw std::runtime_error("can't codegen binary operator for string");
		default:
			throw std::logic_error("can't codegen binary operator for undefined expression type");
		}

		// TODO: produce warning here
	}

	assert(ToExpressionType(left->getType()) == ToExpressionType(right->getType()));

	switch (ToExpressionType(left->getType()))
	{
	case ExpressionType::Int:
		m_stack.push_back(CreateIntegerBinaryExpression(left, right, node.GetOperator(), llvmContext, builder));
		break;
	case ExpressionType::Float:
		m_stack.push_back(CreateFloatBinaryExpression(left, right, node.GetOperator(), llvmContext, builder));
		break;
	case ExpressionType::Bool:
		m_stack.push_back(CreateBooleanBinaryExpression(left, right, node.GetOperator(), llvmContext, builder));
		break;
	default:
		throw std::runtime_error("can't codegen binary operator '" +
			ToString(node.GetOperator()) + "' for " + ToString(ToExpressionType(left->getType())));
	}
}

void ExpressionCodegen::Visit(const LiteralConstantAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();
	llvm::IRBuilder<>& builder = utils.GetBuilder();
	const LiteralConstantAST::Value& constant = node.GetValue();

	// TODO: use boost::static_visitor
	if (constant.type() == typeid(int))
	{
		const int number = boost::get<int>(constant);
		llvm::Value* value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvmContext), number);
		m_stack.push_back(value);
	}
	else if (constant.type() == typeid(double))
	{
		const double number = boost::get<double>(constant);
		llvm::Value* value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(llvmContext), number);
		m_stack.push_back(value);
	}
	else if (constant.type() == typeid(bool))
	{
		const bool boolean = boost::get<bool>(constant);
		llvm::Value* value = llvm::ConstantInt::get(llvm::Type::getInt1Ty(llvmContext), uint64_t(boolean));
		m_stack.push_back(value);
	}
	else if (constant.type() == typeid(std::string))
	{
		const std::string str = boost::get<std::string>(constant);
		llvm::Type* i8 = llvm::Type::getInt8Ty(llvmContext);
		llvm::Constant* constantString = llvm::ConstantDataArray::getString(llvmContext, str, true);
		llvm::ArrayType* arrayType = llvm::ArrayType::get(i8, str.length() + 1);

		llvm::AllocaInst* allocaInst = builder.CreateAlloca(arrayType,
			llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvmContext), uint64_t(str.length() + 1)), "str_alloc");
		llvm::StoreInst* storeInst = builder.CreateStore(constantString, allocaInst);
		(void)storeInst;

		m_stack.push_back(builder.CreateBitCast(allocaInst, llvm::Type::getInt8PtrTy(llvmContext), "str_to_i8_ptr"));
	}
	else
	{
		assert(false);
		throw std::logic_error("Visiting LiteralConstantAST - can't codegen for undefined literal constant type");
	}
}

void ExpressionCodegen::Visit(const UnaryAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();
	llvm::IRBuilder<> & builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::Value* value = Visit(node.GetExpr());
	const ExpressionType type = ToExpressionType(value->getType());

	switch (node.GetOperator())
	{
	case UnaryAST::Plus:
		m_stack.push_back(value);
		break;
	case UnaryAST::Minus:
		m_stack.push_back(CreateNegativeValue(value, builder));
		break;
	case UnaryAST::Negation:
		m_stack.push_back(CreateValueNegation(value, llvmContext, builder));
		break;
	default:
		assert(false);
		throw std::logic_error("Visit(UnaryAST): undefined unary operator");
	}
}

void ExpressionCodegen::Visit(const IdentifierAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();
	llvm::IRBuilder<>& builder = utils.GetBuilder();

	const std::string& name = node.GetName();
	llvm::AllocaInst* variable = m_context.GetVariable(name);

	if (!variable)
	{
		throw std::runtime_error("variable '" + name + "' is not defined");
	}

	llvm::Value* value = builder.CreateLoad(variable, name + "Value");
	m_stack.push_back(value);
}

void ExpressionCodegen::Visit(const FunctionCallExprAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::Function* func = m_context.GetFunction(node.GetName());
	if (!func)
	{
		throw std::runtime_error("calling function '" + node.GetName() + "' that isn't defined");
	}

	if (func->arg_size() != node.GetParamsCount())
	{
		boost::format fmt("function '%1%' expects %2% params, %3% given");
		throw std::runtime_error((fmt % node.GetName() % func->arg_size() % node.GetParamsCount()).str());
	}

	size_t index = 0;
	std::vector<llvm::Value*> params;

	for (llvm::Argument& arg : func->args())
	{
		llvm::Value* value = Visit(node.GetParam(index));

		if (ToExpressionType(value->getType()) != ToExpressionType(arg.getType()))
		{
			llvm::Value* casted = CastValue(value, ToExpressionType(arg.getType()), llvmContext, builder);
			if (!casted)
			{
				auto fmt = boost::format("function '%1%' expects '%2%' as parameter, '%3%' given (can't cast)")
					% func->getName().str()
					% ToString(ToExpressionType(arg.getType()))
					% ToString(ToExpressionType(value->getType()));
				throw std::runtime_error(fmt.str());
			}

			assert(ToExpressionType(casted->getType()) == ToExpressionType(arg.getType()));
			params.push_back(casted);
			++index;
			continue;
		}

		assert(ToExpressionType(value->getType()) == ToExpressionType(arg.getType()));
		params.push_back(value);
		++index;
	}

	if (func->getReturnType()->getTypeID() == llvm::Type::VoidTyID)
	{
		throw std::runtime_error("function '" + func->getName().str() + "' returns void - you can't store the result");
	}
	llvm::Value* value = builder.CreateCall(func, params, "calltmp");
	m_stack.push_back(value);
}

void ExpressionCodegen::Visit(const ArrayElementAccessAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();
	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::AllocaInst* variable = m_context.GetVariable(node.GetName());
	if (!variable)
	{
		throw std::runtime_error("variable '" + node.GetName() + "' is not defined");
	}

	if (!variable->getType()->isPointerTy())
	{
		throw std::runtime_error("variable '" + node.GetName() + "' can't be accessed via index");
	}

	llvm::Value* index = ConvertToIntegerValue(Visit(node.GetIndex()), llvmContext, builder);
	llvm::Value* elementPtr = builder.CreateGEP(builder.CreateLoad(variable, "load_ptr"), index, "get_element_ptr");
	llvm::Value* value = builder.CreateLoad(llvm::Type::getInt8Ty(llvmContext), elementPtr, "load_arr_element");

	if (value->getType()->getTypeID() == llvm::Type::IntegerTyID && value->getType()->getIntegerBitWidth() == 8)
	{
		value = builder.CreateIntCast(value, llvm::Type::getInt32Ty(llvmContext), false, "icasttmp");
	}
	m_stack.push_back(value);
}

// Statement codegen visitor
StatementCodegen::StatementCodegen(CodegenContext& context)
	: m_context(context)
	, m_expressionCodegen(context)
{
}

void StatementCodegen::Visit(const IStatementAST& node)
{
	node.Accept(*this);
}

llvm::BasicBlock* StatementCodegen::GetLastBasicBlockBranch()
{
	return m_branchContinueStack.empty() ? nullptr : m_branchContinueStack.back();
}

void StatementCodegen::Visit(const VariableDeclarationAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();
	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	const std::string& name = node.GetIdentifier().GetName();
	if (m_context.GetVariable(name))
	{
		throw std::runtime_error("variable '" + name + "' is already defined");
	}

	llvm::Type* type = ToLLVMType(node.GetType(), llvmContext);
	llvm::AllocaInst* variable = builder.CreateAlloca(type, nullptr, name + "Ptr");

	llvm::Value* defaultValue = CreateDefaultValue(node.GetType(), llvmContext, builder);
	builder.CreateStore(defaultValue, variable);

	m_context.Define(name, variable);

	if (const IExpressionAST* expression = node.GetExpression())
	{
		llvm::Value* value = m_expressionCodegen.Visit(*expression);

		if (ToExpressionType(value->getType()) != node.GetType())
		{
			llvm::Value* casted = CastValue(value, node.GetType(), llvmContext, builder);
			if (!casted)
			{
				auto fmt = boost::format("can't set expression of type '%1%' to variable '%2%' of type '%3%'")
					% ToString(ToExpressionType(value->getType()))
					% name
					% ToString(node.GetType());
				throw std::runtime_error(fmt.str());
			}

			// TODO: produce warning here
			assert(casted->getType()->getTypeID() == variable->getType()->getPointerElementType()->getTypeID());
			builder.CreateStore(casted, variable);
			return;
		}

		assert(value->getType()->getTypeID() == variable->getType()->getPointerElementType()->getTypeID());
		builder.CreateStore(value, variable);
	}
}

void StatementCodegen::Visit(const AssignStatementAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	const std::string& name = node.GetIdentifier().GetName();
	llvm::AllocaInst* variable = m_context.GetVariable(name);
	if (!variable)
	{
		throw std::runtime_error("can't assign because variable '" + name + "' is not defined");
	}

	llvm::Value* value = m_expressionCodegen.Visit(node.GetExpr());

	if (ToExpressionType(value->getType()) != ToExpressionType(variable->getType()->getPointerElementType()))
	{
		llvm::Value* casted = CastValue(value, ToExpressionType(variable->getType()->getPointerElementType()), llvmContext, builder);
		if (!casted)
		{
			auto fmt = boost::format("can't set expression of type '%1%' to variable '%2%' of type '%3%'")
				% ToString(ToExpressionType(value->getType()))
				% name
				% ToString(ToExpressionType(variable->getType()->getPointerElementType()));
			throw std::runtime_error(fmt.str());
		}

		// TODO: produce warning here
		assert(casted->getType()->getTypeID() == variable->getType()->getPointerElementType()->getTypeID());
		builder.CreateStore(casted, variable);
		return;
	}

	assert(value->getType()->getTypeID() == variable->getType()->getPointerElementType()->getTypeID());
	builder.CreateStore(value, variable);
}

void StatementCodegen::Visit(const ArrayElementAssignAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();
	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::AllocaInst* variable = m_context.GetVariable(node.GetName());
	if (!variable)
	{
		throw std::runtime_error("variable '" + node.GetName() + "' is not defined");
	}

	if (!variable->getType()->isPointerTy())
	{
		throw std::runtime_error("variable '" + node.GetName() + "' can't be accessed via index");
	}

	llvm::Value* index = ConvertToIntegerValue(m_expressionCodegen.Visit(node.GetIndex()), llvmContext, builder);

	llvm::Value* value = ConvertToIntegerValue(m_expressionCodegen.Visit(node.GetExpression()), llvmContext, builder);
	if (value->getType()->getTypeID() == llvm::Type::IntegerTyID && value->getType()->getIntegerBitWidth() != 8)
	{
		value = builder.CreateIntCast(value, llvm::Type::getInt8Ty(llvmContext), false, "icasttmp");
	}

	llvm::Value* elementPtr = builder.CreateGEP(builder.CreateLoad(variable, "load_ptr"), index, "get_element_ptr");

	assert(value->getType()->getTypeID() == llvm::Type::IntegerTyID && value->getType()->getIntegerBitWidth() == 8);
	llvm::StoreInst* storeInst = builder.CreateStore(value, elementPtr);
	(void)storeInst;
}

void StatementCodegen::Visit(const ReturnStatementAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::Function* func = builder.GetInsertBlock()->getParent();
	if (func->getReturnType()->getTypeID() == llvm::Type::VoidTyID)
	{
		if (node.GetExpression())
		{
			llvm::Value* value = m_expressionCodegen.Visit(*node.GetExpression());
			const ExpressionType type = ToExpressionType(value->getType());
			throw std::runtime_error("function '" + func->getName().str() + "' can't return value of type " + ToString(type));
		}
		builder.CreateRet(nullptr);
		return;
	}

	const ExpressionType funcReturnType = ToExpressionType(func->getReturnType());
	if (!node.GetExpression())
	{
		throw std::runtime_error("return statement must have expression of type" + ToString(funcReturnType));
	}

	llvm::Value* value = m_expressionCodegen.Visit(*node.GetExpression());
	if (ToExpressionType(value->getType()) != funcReturnType)
	{
		value = CastValue(value, funcReturnType, llvmContext, builder);
		if (!value)
		{
			auto fmt = boost::format("returning expression of type %1% must be at least convertible to function return type (%2%)")
				% ToString(ToExpressionType(value->getType()))
				% ToString(funcReturnType);
			throw std::runtime_error(fmt.str());
		}
	}

	assert(ToExpressionType(value->getType()) == funcReturnType);
	builder.CreateRet(value);
}

void StatementCodegen::Visit(const IfStatementAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::IRBuilder<> & builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::Function* func = builder.GetInsertBlock()->getParent();

	llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(llvmContext, "then", func);
	llvm::BasicBlock* elseBlock = llvm::BasicBlock::Create(llvmContext, "else", func);
	llvm::BasicBlock* continueBlock = llvm::BasicBlock::Create(llvmContext, "continue", func);

	llvm::Value* value = m_expressionCodegen.Visit(node.GetExpr());
	value = ConvertToBooleanValue(value, llvmContext, builder);
	builder.CreateCondBr(value, thenBlock, elseBlock);

	auto putBrAfterBranchInsertionIfNecessary = [&](llvm::BasicBlock* branch) {
		if (!branch->getTerminator())
		{
			builder.CreateBr(continueBlock);
			return;
		}

		if (!m_branchContinueStack.empty())
		{
			const bool hasTerminated = bool(m_branchContinueStack.back()->getTerminator());
			m_branchContinueStack.pop_back();
			if (!hasTerminated)
			{
				builder.CreateBr(continueBlock);
			}
		}
	};

	builder.SetInsertPoint(thenBlock);
	Visit(node.GetThenStmt());
	putBrAfterBranchInsertionIfNecessary(thenBlock);

	builder.SetInsertPoint(elseBlock);
	if (node.GetElseStmt())
	{
		Visit(*node.GetElseStmt());
	}
	putBrAfterBranchInsertionIfNecessary(elseBlock);

	builder.SetInsertPoint(continueBlock);
	m_branchContinueStack.push_back(continueBlock);
}

void StatementCodegen::Visit(const WhileStatementAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::IRBuilder<> & builder = utils.GetBuilder();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();

	llvm::Function* func = builder.GetInsertBlock()->getParent();

	llvm::BasicBlock* body = llvm::BasicBlock::Create(llvmContext, "loop", func);
	llvm::BasicBlock* afterLoop = llvm::BasicBlock::Create(llvmContext, "afterloop", func);

	llvm::Value* value = ConvertToBooleanValue(
		m_expressionCodegen.Visit(node.GetExpr()), llvmContext, builder);
	builder.CreateCondBr(value, body, afterLoop);

	auto putBrAfterBranchInsertionIfNecessary = [&](llvm::BasicBlock* branch) {
		if (!branch->getTerminator())
		{
			value = ConvertToBooleanValue(m_expressionCodegen.Visit(node.GetExpr()), llvmContext, builder);
			builder.CreateCondBr(value, body, afterLoop);
		}
		if (!m_branchContinueStack.empty() && !m_branchContinueStack.back()->getTerminator())
		{
			builder.SetInsertPoint(m_branchContinueStack.back());
			value = ConvertToBooleanValue(m_expressionCodegen.Visit(node.GetExpr()), llvmContext, builder);
			builder.CreateCondBr(value, body, afterLoop);
		}
		if (!m_branchContinueStack.empty())
		{
			m_branchContinueStack.pop_back();
		}
	};

	builder.SetInsertPoint(body);
	Visit(node.GetStatement());
	putBrAfterBranchInsertionIfNecessary(body);

	builder.SetInsertPoint(afterLoop);
	m_branchContinueStack.push_back(afterLoop);
}

void StatementCodegen::Visit(const CompositeStatementAST& node)
{
	ContextScopeHelper scopedContext(m_context);
	llvm::IRBuilder<>& builder = m_context.GetUtils().GetBuilder();

	for (size_t i = 0; i < node.GetCount(); ++i)
	{
		node.GetStatement(i).Accept(*this);
		if (builder.GetInsertBlock()->getTerminator())
		{
			break;
		}
		// TODO: produce warning about unreachable code
	}
}

void StatementCodegen::Visit(const PrintAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();
	llvm::IRBuilder<> & builder = utils.GetBuilder();

	std::vector<llvm::Value*> expressions(node.GetParamsCount());
	for (size_t i = 0; i < expressions.size(); ++i)
	{
		expressions[i] = m_expressionCodegen.Visit(node.GetExpression(i));
		if (ToExpressionType(expressions[i]->getType()) == ExpressionType::Bool)
		{
			expressions[i] = ConvertToIntegerValue(expressions[i], llvmContext, builder);
		}
	}

	if (expressions.empty() || ToExpressionType(expressions.front()->getType()) != ExpressionType::String)
	{
		throw std::runtime_error("print statement requires string as first argument");
	}

	builder.CreateCall(m_context.GetPrintf(), expressions, "printtmp");
}

void StatementCodegen::Visit(const FunctionCallStatementAST& node)
{
	CodegenUtils& utils = m_context.GetUtils();
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();
	llvm::IRBuilder<>& builder = utils.GetBuilder();

	const FunctionCallExprAST& call = node.GetCallAsDerived();
	llvm::Function* func = m_context.GetFunction(call.GetName());
	if (!func)
	{
		throw std::runtime_error("calling function '" + call.GetName() + "' that isn't defined");
	}

	if (func->getReturnType()->getTypeID() != llvm::Type::VoidTyID)
	{
		llvm::Value* value = m_expressionCodegen.Visit(node.GetCall());
		(void)value;
		// TODO: produce warning about unused function result
		return;
	}

	if (func->arg_size() != call.GetParamsCount())
	{
		boost::format fmt("function '%1%' expects %2% params, %3% given");
		throw std::runtime_error((fmt % call.GetName() % func->arg_size() % call.GetParamsCount()).str());
	}

	size_t index = 0;
	std::vector<llvm::Value*> params;

	for (llvm::Argument& arg : func->args())
	{
		llvm::Value* value = m_expressionCodegen.Visit(call.GetParam(index));

		if (ToExpressionType(value->getType()) != ToExpressionType(arg.getType()))
		{
			llvm::Value* casted = CastValue(value, ToExpressionType(arg.getType()), llvmContext, builder);
			if (!casted)
			{
				auto fmt = boost::format("function '%1%' expects '%2%' as parameter, '%3%' given (can't cast)")
					% func->getName().str()
					% ToString(ToExpressionType(arg.getType()))
					% ToString(ToExpressionType(value->getType()));
				throw std::runtime_error(fmt.str());
			}

			assert(ToExpressionType(casted->getType()) == ToExpressionType(arg.getType()));
			params.push_back(casted);
			++index;
			continue;
		}

		assert(ToExpressionType(value->getType()) == ToExpressionType(arg.getType()));
		params.push_back(value);
		++index;
	}

	builder.CreateCall(func, params);
}

Codegen::Codegen(CodegenContext& context)
	: m_context(context)
{
}

void Codegen::Generate(const ProgramAST& program)
{
	for (size_t i = 0; i < program.GetFunctionsCount(); ++i)
	{
		GenerateFunc(program.GetFunction(i));
	}
}

void Codegen::Generate(const IStatementAST& statement)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();
	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::Module& llvmModule = utils.GetModule();

	const std::string& name("main");

	llvm::Type* returnType = llvm::Type::getInt32Ty(llvmContext);
	llvm::FunctionType* funcType = llvm::FunctionType::get(returnType, false);
	llvm::Function* llvmFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &llvmModule);

	ContextScopeHelper scopedContext(m_context);

	llvm::BasicBlock* bb = llvm::BasicBlock::Create(llvmContext, name + "_entry", llvmFunc);
	builder.SetInsertPoint(bb);

	StatementCodegen statementCodegen(m_context);
	statementCodegen.Visit(statement);

	std::string output;
	llvm::raw_string_ostream out(output);

	if (llvm::verifyFunction(*llvmFunc, &out))
	{
//		utils.GetModule().dump();
		llvmFunc->eraseFromParent();
		throw std::runtime_error(out.str());
	}

	m_context.AddFunction(name, llvmFunc);
}

void Codegen::GenerateFunc(const FunctionAST& func)
{
	CodegenUtils& utils = m_context.GetUtils();

	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();
	llvm::IRBuilder<>& builder = utils.GetBuilder();
	llvm::Module& llvmModule = utils.GetModule();

	const std::string& name = func.GetIdentifier().GetName();

	llvm::Type* returnType = func.GetReturnType() ?
		ToLLVMType(*func.GetReturnType(), llvmContext) :
		llvm::Type::getVoidTy(llvmContext);

	std::vector<llvm::Type*> argumentTypes;
	argumentTypes.reserve(func.GetParams().size());
	for (const FunctionAST::Param& param : func.GetParams())
	{
		argumentTypes.push_back(ToLLVMType(param.second, llvmContext));
	}

	llvm::FunctionType* funcType = llvm::FunctionType::get(returnType, argumentTypes, false);
	llvm::Function* llvmFunc = llvm::Function::Create(
		funcType, llvm::Function::ExternalLinkage, name, &llvmModule);

	ContextScopeHelper scopedContext(m_context);

	llvm::BasicBlock* bb = llvm::BasicBlock::Create(llvmContext, name + "_entry", llvmFunc);
	builder.SetInsertPoint(bb);

	size_t index = 0;
	for (llvm::Argument& argument : llvmFunc->args())
	{
		assert(index < func.GetParams().size());
		const FunctionAST::Param& param = func.GetParams()[index];
		argument.setName(func.GetParams()[index].first);

		llvm::AllocaInst* variable = builder.CreateAlloca(ToLLVMType(param.second, llvmContext), nullptr, param.first + "Ptr");
		m_context.Define(param.first, variable);
		builder.CreateStore(&argument, variable);

		++index;
	}

	StatementCodegen statementCodegen(m_context);
	statementCodegen.Visit(func.GetStatement());

	if (llvm::BasicBlock* lastContinueBranch = statementCodegen.GetLastBasicBlockBranch())
	{
		if (llvmFunc->getReturnType()->getTypeID() == llvm::Type::VoidTyID && !lastContinueBranch->getTerminator())
		{
			builder.SetInsertPoint(lastContinueBranch);
			builder.CreateRet(nullptr);
		}
	}
	else
	{
		if (llvmFunc->getReturnType()->getTypeID() == llvm::Type::VoidTyID && !llvmFunc->getBasicBlockList().back().getTerminator())
		{
			builder.SetInsertPoint(&llvmFunc->getBasicBlockList().back());
			builder.CreateRet(nullptr);
		}
	}

	for (llvm::BasicBlock& basicBlock : llvmFunc->getBasicBlockList())
	{
		if (!basicBlock.getTerminator())
		{
			//llvmFunc->dump();
			throw std::runtime_error("every path must have return statement");
		}
	}

	std::string output;
	llvm::raw_string_ostream out(output);

	if (llvm::verifyFunction(*llvmFunc, &out))
	{
		//utils.GetModule().dump();
		llvmFunc->eraseFromParent();
		throw std::runtime_error(out.str());
	}

	m_context.AddFunction(func.GetIdentifier().GetName(), llvmFunc);
}

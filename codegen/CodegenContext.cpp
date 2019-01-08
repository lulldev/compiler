#include "CodegenContext.h"

namespace
{
llvm::Function* CreatePrintfBuiltinFunction(CodegenUtils& utils)
{
	llvm::LLVMContext& llvmContext = utils.GetLLVMContext();
	llvm::Module& llvmModule = utils.GetModule();

	// ������������ ������������ �������� ������� printf - char*
	std::vector<llvm::Type*> argTypes = { llvm::Type::getInt8PtrTy(llvmContext) };

	// �������, ��� ������� ������ int32, � ����� ��� ��� ����� ���������� ����� ����������
	llvm::FunctionType* fnType = llvm::FunctionType::get(
		llvm::Type::getInt32Ty(llvmContext), argTypes, true);

	// ������� ������� printf, ������� ����� "����������" � ����������� ������ �����
	return llvm::Function::Create(fnType, llvm::Function::ExternalLinkage, "printf", &llvmModule);
}
}

CodegenUtils::CodegenUtils()
	: m_context()
	, m_builder(m_context)
	, m_module("Module", m_context)
{
}

llvm::LLVMContext& CodegenUtils::GetLLVMContext()
{
	return m_context;
}

llvm::IRBuilder<>& CodegenUtils::GetBuilder()
{
	return m_builder;
}

llvm::Module& CodegenUtils::GetModule()
{
	return m_module;
}

CodegenContext::CodegenContext()
	: m_utils()
	, m_scopes()
	, m_printf(CreatePrintfBuiltinFunction(m_utils))
{
}

void CodegenContext::PushScope()
{
	m_scopes.PushScope();
}

void CodegenContext::PopScope()
{
	m_scopes.PopScope();
}

void CodegenContext::Define(const std::string& name, llvm::AllocaInst* value)
{
	m_scopes.Define(name, value);
}

void CodegenContext::Assign(const std::string& name, llvm::AllocaInst* value)
{
	m_scopes.Assign(name, value);
}

llvm::AllocaInst* CodegenContext::GetVariable(const std::string& name)
{
	auto variable = m_scopes.GetValue(name);
	return variable.value_or(nullptr);
}

llvm::Function* CodegenContext::GetPrintf()
{
	return m_printf;
}

CodegenUtils& CodegenContext::GetUtils()
{
	return m_utils;
}

void CodegenContext::AddFunction(const std::string& name, llvm::Function* func)
{
	assert(func);
	m_functions[name] = func;
}

llvm::Function* CodegenContext::GetFunction(const std::string& name)
{
	auto found = m_functions.find(name);
	if (found != m_functions.end())
	{
		return found->second;
	}
	return nullptr;
}

void CodegenContext::Dump(std::ostream& out)
{
	llvm::raw_os_ostream os(out);
	m_utils.GetModule().print(os, nullptr);
}

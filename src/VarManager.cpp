#include "VarManager.h"
#include <assert.h>
#include <algorithm>
VarManager::VarManager(PhreeqcRM* rm_ptr_in) 
{
	this->VariantMap[VARS::ComponentCount] = 
		BMIVariant(&VarManager::ComponentCount_var, "ComponentCount");
	//this->VariantMap[VARS::Porosity] =
	//	BMIVariant(&VarManager::Porosity_var, "Porosity");
	//this->VariantMap["ComponentCount"] = BMIVariant(&VarManager::ComponentCount_var);
	///!!!VarFunction x = &VarManager::ComponentCount_var;
	///!!! (this->*x)(rm_ptr); // Remember this !!!///
	//auto it = VariantMap.begin();
	//VarFunction x = it->second.GetFn();
	//(this->*x)();
	rm_ptr = rm_ptr_in;
	this->task = VarManager::VAR_TASKS::no_op;
	this->CurrentVar = VarManager::VARS::NotFound;
	//auto it = VarVariantMap.begin();
	//VarFunction x = it->second.GetFn(rm_ptr);
	//x(rm_ptr);
	// Make EnumMap
	for (auto it = VariantMap.begin(); it != VariantMap.end(); it++)
	{
		std::string name_lc = it->second.GetName();
		std::transform(name_lc.begin(), name_lc.end(), name_lc.begin(), tolower);
		EnumMap[name_lc] = it->first;
	}
}
void VarManager::RM2BMIUpdate(std::string name)
{
	if (this->PointerSet.size() == 0) return;
	VarManager::VARS v_enum = this->GetEnum(name);
	if (this->GetCurrentVar() != v_enum) return;
	auto it = this->VariantMap.find(v_enum);
	if (it != VariantMap.end())
	{
		this->task = VarManager::VAR_TASKS::RMUpdate;
		VarFunction f =  it->second.GetFn(); 
		(this->*f)();
	}
	return;
}
VarManager::VARS VarManager::GetEnum(const std::string name)
{
	std::string name_lc = name;
	std::transform(name_lc.begin(), name_lc.end(), name_lc.begin(), tolower);
	auto m_it = EnumMap.find(name_lc);
	if (m_it != EnumMap.end())
	{
		return m_it->second;
	}
	return VarManager::VARS::NotFound;
}
//// Start_var
void VarManager::ComponentCount_var()
{
	this->SetCurrentVar(VarManager::VARS::ComponentCount);
	BMIVariant& bv = this->VariantMap[VarManager::VARS::ComponentCount];
	if (!bv.GetInitialized())
	{
		BMIVariant& bv = this->VariantMap[VarManager::VARS::ComponentCount];
		int Itemsize = (int)sizeof(int);
		int Nbytes = (int)sizeof(int);
		//std::string units, set, get, ptr, Nbytes, Itemsize
		bv.SetBasic("names", false, true, true, Nbytes, Itemsize);
		bv.SetTypes("int", "integer", "int");
		bv.SetIVar(rm_ptr->GetComponentCount());
		bv.SetInitialized(true);
	}
	switch (this->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		int v = rm_ptr->GetComponentCount();
		bv.SetIVar(v);
		bv.SetVoidPtr((void*)(bv.GetIVarPtr()));
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
	{
		int v = rm_ptr->GetComponentCount();
		bv.SetIVar(v);
		break;
	}
	case VarManager::VAR_TASKS::SetVar:
		assert(false);
		break;
	case VarManager::VAR_TASKS::RMUpdate:
	{
		assert(false);
		break;
	}	
	case VarManager::VAR_TASKS::UpdateState:
	{
		assert(false);
		break;
	}
	case VarManager::VAR_TASKS::no_op:
		break;
	}
	this->VarExchange.Copy(bv);
	this->SetCurrentVar(VarManager::VARS::NotFound);
}

////////////////////////////////

#ifdef SKIP
void VarManager::ComponentCount_var()
{
	static int ComponentCount;
	//
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("ComponentCount", "names", false, true, true, Nbytes, Itemsize);
	bv.SetTypes("int", "integer", "int");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		ComponentCount = rm_ptr->GetComponentCount();
		this->SetVoidPtr((void*)&ComponentCount);
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.i_var = rm_ptr->GetComponentCount();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Components_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<std::string> Components;
	static std::vector<const char*> CharVector;
	//
	std::vector<std::string> comps = rm_ptr->GetComponents();
	size_t size = 0;
	for (size_t i = 0; i < comps.size(); i++)
	{
		if (comps[i].size() > size) size = comps[i].size();
	}
	int Itemsize = (int)size;
	int Nbytes = (int)(size * comps.size());
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("Components", "names", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("std::vector<std::string>", "character(len=:),allocatable,dimension(:)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			Components = rm_ptr->GetComponents();
			initialized = true;
			for (size_t i = 0; i < Components.size(); i++)
			{
				CharVector.push_back(Components[i].c_str());
			}
		}
		rm_ptr->bmi_variant.SetCharVector(CharVector);
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.StringVector = rm_ptr->GetComponents();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}

void VarManager::Concentrations_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<double> Concentrations;
	//
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		rm_ptr->GetConcentrations(rm_ptr->bmi_variant.DoubleVector);
		assert(Concentrations.size() == rm_ptr->bmi_variant.DoubleVector.size());
		memcpy(Concentrations.data(),
			rm_ptr->bmi_variant.DoubleVector.data(),
			Concentrations.size() * sizeof(double));
		return;
	}
	int Itemsize = (int)sizeof(double);
	int Nbytes = (int)sizeof(double) *
		rm_ptr->GetGridCellCount() * rm_ptr->GetComponentCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("Concentrations", "mol L-1", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			rm_ptr->GetConcentrations(Concentrations);
			initialized = true;
			rm_ptr->GetUpdateMap().insert("Concentrations");
		}
		rm_ptr->bmi_variant.SetVoidPtr((void*)Concentrations.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->GetConcentrations(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::SetVar:
		if (initialized)
		{
			assert(Concentrations.size() == rm_ptr->bmi_variant.DoubleVector.size());
			memcpy(Concentrations.data(),
				rm_ptr->bmi_variant.DoubleVector.data(),
				Concentrations.size() * sizeof(double));
		}
		rm_ptr->SetConcentrations(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Density_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<double> Density;
	//
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		rm_ptr->GetDensity(rm_ptr->bmi_variant.DoubleVector);
		assert(Density.size() == rm_ptr->bmi_variant.DoubleVector.size());
		memcpy(Density.data(),
			rm_ptr->bmi_variant.DoubleVector.data(),
			Density.size() * sizeof(double));
		return;
	}
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetGridCellCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("Density", "kg L-1", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			rm_ptr->GetDensity(Density);
			initialized = true;
			rm_ptr->GetUpdateMap().insert("Density");
		}
		rm_ptr->bmi_variant.SetVoidPtr((void*)Density.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->GetDensity(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::SetVar:
		// SetDensity does not affect GetDensity
		rm_ptr->SetDensity(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::ErrorString_var(PhreeqcRM* rm_ptr)
{

	int Itemsize = (int)rm_ptr->GetErrorString().size();
	int Nbytes = Itemsize;
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("ErrorString", "error", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("std::string", "character", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.string_var = rm_ptr->GetErrorString();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::FilePrefix_var(PhreeqcRM* rm_ptr)
{
	int Itemsize = rm_ptr->GetFilePrefix().size();
	int Nbytes = Itemsize;
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("FilePrefix", "name", true, true, false, Nbytes, Itemsize);
	bv.SetTypes("std::string", "character", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.string_var = rm_ptr->GetFilePrefix();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->SetFilePrefix(rm_ptr->bmi_variant.string_var);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Gfw_var(PhreeqcRM* rm_ptr)
{
	static std::vector<double> Gfw;
	bool initialized = false;
	//
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetComponentCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("Gfw", "g mol-1", false, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			Gfw = rm_ptr->GetGfw();
			initialized = true;
		}
		rm_ptr->bmi_variant.SetVoidPtr(Gfw.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetGfw();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::GridCellCount_var(PhreeqcRM* rm_ptr)
{
	static int GridCellCount;
	//
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("GridCellCount", "count", false, true, true, Nbytes, Itemsize);
	bv.SetTypes("int", "integer", "int");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		GridCellCount = rm_ptr->GetGridCellCount();
		rm_ptr->bmi_variant.SetVoidPtr((void*)&GridCellCount);
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.i_var = rm_ptr->GetGridCellCount();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::InputVarNames_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<std::string> InputVarNames;
	static std::vector<const char*> CharVector;
	//
	PhreeqcRM::BMI_TASKS task_save = rm_ptr->task;
	std::vector<std::string> names = rm_ptr->GetInputVarNames();
	rm_ptr->task = task_save;
	size_t size = 0;
	for (size_t i = 0; i < names.size(); i++)
	{
		if (names[i].size() > size) size = names[i].size();
	}
	int Itemsize = (int)size;
	int Nbytes = (int)(size * names.size());
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("InputVarNames", "names", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("std::vector<std::string>", "character(len=:),allocatable,dimension(:)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			InputVarNames = rm_ptr->GetInputVarNames();
			initialized = true;
			for (size_t i = 0; i < InputVarNames.size(); i++)
			{
				CharVector.push_back(InputVarNames[i].c_str());
			}
		}
		rm_ptr->bmi_variant.SetCharVector(CharVector);
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.StringVector = rm_ptr->GetInputVarNames();
		rm_ptr->bmi_variant.bmi_var = bv;
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::NthSelectedOutput_var(PhreeqcRM* rm_ptr)
{
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("NthSelectedOutput", "id", true, false, false, Nbytes, Itemsize);
	bv.SetTypes("int", "integer", "int");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->SetNthSelectedOutput(rm_ptr->bmi_variant.i_var);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::OutputVarNames_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<std::string> OutputVarNames;
	static std::vector<const char*> CharVector;
	//
	PhreeqcRM::BMI_TASKS task_save = rm_ptr->task;
	std::vector<std::string> names = rm_ptr->GetOutputVarNames();
	rm_ptr->task = task_save;
	size_t size = 0;
	for (size_t i = 0; i < names.size(); i++)
	{
		if (names[i].size() > size) size = names[i].size();
	}
	int Itemsize = (int)size;
	int Nbytes = (int)(size * names.size());
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("OutputVarNames", "names", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("std::vector<std::string>", "character(len=:),allocatable,dimension(:)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			OutputVarNames = rm_ptr->GetOutputVarNames();
			initialized = true;
			for (size_t i = 0; i < OutputVarNames.size(); i++)
			{
				CharVector.push_back(OutputVarNames[i].c_str());
			}
		}
		rm_ptr->bmi_variant.SetCharVector(CharVector);
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.StringVector = rm_ptr->GetOutputVarNames();
		rm_ptr->bmi_variant.bmi_var = bv;
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Saturation_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<double> Saturation;
	//
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		rm_ptr->GetSaturation(rm_ptr->bmi_variant.DoubleVector);
		assert(Saturation.size() == rm_ptr->bmi_variant.DoubleVector.size());
		memcpy(Saturation.data(),
			rm_ptr->bmi_variant.DoubleVector.data(),
			Saturation.size() * sizeof(double));
		return;
	}
	//
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetGridCellCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("Saturation", "unitless", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			rm_ptr->GetSaturation(Saturation);
			initialized = true;
			rm_ptr->GetUpdateMap().insert("Saturation");
		}
		rm_ptr->bmi_variant.SetVoidPtr((void*)Saturation.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->GetSaturation(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::SetVar:
		// SetSaturation does not affect GetSaturation
		rm_ptr->SetSaturation(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::SelectedOutput_var(PhreeqcRM* rm_ptr)
{
	int Itemsize = (int)sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetSelectedOutputRowCount() *
		rm_ptr->GetSelectedOutputColumnCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("SelectedOutput", "user", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->GetSelectedOutput(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::SelectedOutputColumnCount_var(PhreeqcRM* rm_ptr)
{
	static int SelectedOutputColumnCount;
	//
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("SelectedOutputColumnCount", "count", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("int", "integer", "int");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.i_var = rm_ptr->GetSelectedOutputColumnCount();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::SelectedOutputCount_var(PhreeqcRM* rm_ptr)
{
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("SelectedOutputCount", "count", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("int", "integer", "int");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.i_var = rm_ptr->GetSelectedOutputCount();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::SelectedOutputHeadings_var(PhreeqcRM* rm_ptr)
{
	std::vector<std::string> headings;
	rm_ptr->GetSelectedOutputHeadings(headings);
	size_t size = 0;
	for (size_t i = 0; i < headings.size(); i++)
	{
		if (headings[i].size() > size) size = headings[i].size();
	}
	int Itemsize = (int)size;
	int Nbytes = (int)(size * headings.size());
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("SelectedOutputHeadings", "names", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("std::vector<std::string>", "character(len=:),allocatable,dimension(:)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->GetSelectedOutputHeadings(rm_ptr->bmi_variant.StringVector);
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::SelectedOutputRowCount_var(PhreeqcRM* rm_ptr)
{
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("SelectedOutputRowCount", "count", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("int", "integer", "int");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.i_var = rm_ptr->GetSelectedOutputRowCount();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::SolutionVolume_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<double> SolutionVolume;
	//
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetSolutionVolume();
		assert(SolutionVolume.size() == rm_ptr->bmi_variant.DoubleVector.size());
		memcpy(SolutionVolume.data(),
			rm_ptr->bmi_variant.DoubleVector.data(),
			SolutionVolume.size() * sizeof(double));
		return;
	}
	//
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetGridCellCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("SolutionVolume", "L", false, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			SolutionVolume = rm_ptr->GetSolutionVolume();
			initialized = true;
			rm_ptr->GetUpdateMap().insert("SolutionVolume");
		}
		rm_ptr->bmi_variant.SetVoidPtr((void*)SolutionVolume.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetSolutionVolume();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Time_var(PhreeqcRM* rm_ptr)
{
	static double Time;
	//
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		Time = rm_ptr->GetTime();
		return;
	}
	//
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize;
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("Time", "s", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "float");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		Time = rm_ptr->GetTime();
		rm_ptr->bmi_variant.SetVoidPtr(&Time);
		rm_ptr->GetUpdateMap().insert("Time");
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.d_var = rm_ptr->GetTime();
		break;
	case VarManager::VAR_TASKS::SetVar:
		Time = rm_ptr->bmi_variant.d_var;
		rm_ptr->SetTime(rm_ptr->bmi_variant.d_var);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::TimeStep_var(PhreeqcRM* rm_ptr)
{
	static double TimeStep;
	//
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		TimeStep = rm_ptr->GetTimeStep();
		return;
	}
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize;
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("TimeStep", "s", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "float");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		TimeStep = rm_ptr->GetTimeStep();
		rm_ptr->bmi_variant.SetVoidPtr((void*)&TimeStep);
		rm_ptr->GetUpdateMap().insert("TimeStep");
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.d_var = rm_ptr->GetTimeStep();
		break;
	case VarManager::VAR_TASKS::SetVar:
		TimeStep = rm_ptr->bmi_variant.d_var;
		rm_ptr->SetTimeStep(rm_ptr->bmi_variant.d_var);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::CurrentSelectedOutputUserNumber_var(PhreeqcRM* rm_ptr)
{
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("CurrentSelectedOutputUserNumber", "id", false, true, false, Nbytes, Itemsize);
	bv.SetTypes("int", "integer", "int");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.i_var = rm_ptr->GetCurrentSelectedOutputUserNumber();
		break;
	case VarManager::VAR_TASKS::SetVar:
		rm_ptr->bmi_variant.NotImplemented = true;
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Porosity_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<double> Porosity;
	// 
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetPorosity();
		assert(Porosity.size() == rm_ptr->bmi_variant.DoubleVector.size());
		memcpy(Porosity.data(),
			rm_ptr->bmi_variant.DoubleVector.data(),
			Porosity.size() * sizeof(double));
		return;
	}
	//
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetGridCellCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("Porosity", "unitless", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			Porosity = rm_ptr->GetPorosity();
			initialized = true;
			rm_ptr->GetUpdateMap().insert("Porosity");
		}
		rm_ptr->bmi_variant.SetVoidPtr((void*)Porosity.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetPorosity();
		break;
	case VarManager::VAR_TASKS::SetVar:
		if (initialized)
		{
			assert(Porosity.size() == rm_ptr->bmi_variant.DoubleVector.size());
			memcpy(Porosity.data(),
				rm_ptr->bmi_variant.DoubleVector.data(),
				Nbytes);
		}
		rm_ptr->SetPorosity(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Pressure_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<double> Pressure;
	// 
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetPressure();
		assert(Pressure.size() == rm_ptr->bmi_variant.DoubleVector.size());
		memcpy(Pressure.data(),
			rm_ptr->bmi_variant.DoubleVector.data(),
			Pressure.size() * sizeof(double));
		return;
	}
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetGridCellCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("Pressure", "atm", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			Pressure = rm_ptr->GetPressure();
			initialized = true;
			rm_ptr->GetUpdateMap().insert("Pressure");
		}
		rm_ptr->bmi_variant.SetVoidPtr((void*)Pressure.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetPressure();
		break;
	case VarManager::VAR_TASKS::SetVar:
		if (initialized)
		{
			assert(Pressure.size() == rm_ptr->bmi_variant.DoubleVector.size());
			memcpy(Pressure.data(),
				rm_ptr->bmi_variant.DoubleVector.data(),
				Pressure.size() * sizeof(double));
		}
		rm_ptr->SetPressure(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::SelectedOutputOn_var(PhreeqcRM* rm_ptr)
{
	static bool SelectedOutputOn;
	//
	//
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		SelectedOutputOn = rm_ptr->GetSelectedOutputOn();
		return;
	}
	int Itemsize = (int)sizeof(int);
	int Nbytes = (int)sizeof(int);
	//name, std::string units, set, get, ptr, Nbytes, Itemsize
	BMI_Var bv = BMI_Var("SelectedOutputOn", "bool", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("bool", "logical", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		SelectedOutputOn = rm_ptr->GetSelectedOutputOn();
		rm_ptr->bmi_variant.SetVoidPtr((void*)&SelectedOutputOn);
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.b_var = rm_ptr->GetSelectedOutputOn();
		break;
	case VarManager::VAR_TASKS::SetVar:
		SelectedOutputOn = rm_ptr->bmi_variant.b_var;
		rm_ptr->SetSelectedOutputOn(rm_ptr->bmi_variant.b_var);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
void VarManager::Temperature_var(PhreeqcRM* rm_ptr)
{
	static bool initialized = false;
	static std::vector<double> Temperature;
	// 
	if (rm_ptr->task == VarManager::VAR_TASKS::Update)
	{
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetTemperature();
		assert(Temperature.size() == rm_ptr->bmi_variant.DoubleVector.size());
		memcpy(Temperature.data(),
			rm_ptr->bmi_variant.DoubleVector.data(),
			Temperature.size() * sizeof(double));
		return;
	}
	//
	int Itemsize = sizeof(double);
	int Nbytes = Itemsize * rm_ptr->GetGridCellCount();
	//name, std::string units, set, get, ptr, Nbytes, Itemsize  
	BMI_Var bv = BMI_Var("Temperature", "C", true, true, true, Nbytes, Itemsize);
	bv.SetTypes("double", "real(kind=8)", "");
	rm_ptr->bmi_variant.bmi_var = bv;
	switch (rm_ptr->task)
	{
	case VarManager::VAR_TASKS::GetPtr:
	{
		if (!initialized)
		{
			Temperature = rm_ptr->GetTemperature();
			initialized = true;
			rm_ptr->GetUpdateMap().insert("Temperature");
		}
		rm_ptr->bmi_variant.SetVoidPtr((void*)Temperature.data());
		break;
	}
	case VarManager::VAR_TASKS::GetVar:
		rm_ptr->bmi_variant.DoubleVector = rm_ptr->GetTemperature();
		break;
	case VarManager::VAR_TASKS::SetVar:
		if (initialized)
		{
			assert(Temperature.size() == rm_ptr->bmi_variant.DoubleVector.size());
			memcpy(Temperature.data(),
				rm_ptr->bmi_variant.DoubleVector.data(),
				Temperature.size() * sizeof(double));
		}
		rm_ptr->SetTemperature(rm_ptr->bmi_variant.DoubleVector);
		break;
	case VarManager::VAR_TASKS::Info:
		break;
	case VarManager::VAR_TASKS::no_op:
		break;
	}
}
#endif

//////////////////

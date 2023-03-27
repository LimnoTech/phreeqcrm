#if !defined(BMIPHREEQCRM_H_INCLUDED)
#define BMIPHREEQCRM_H_INCLUDED
#include <map>
#include "PhreeqcRM.h"
#include "BMI_Var.h"
#include "bmi.hxx"
class NotImplemented : public std::logic_error {
public:
    NotImplemented() : std::logic_error("Not Implemented") { };
};
class BMI_Variant
{
public:
    BMI_Variant()
    {
        this->Clear();
    }
    BMI_Var                  bmi_var;
    bool                     b_var;
    int                      i_var;
    double                   d_var;
    std::string              string_var;
    std::vector<int>         IntVector;
    std::vector<double>      DoubleVector;
    std::vector<std::string> StringVector;
    bool                     NotImplemented;
    void* void_ptr;
    std::vector<const char*> CharVector;
    bool GetGet() { return this->bmi_var.GetGet(); }
    void SetGet(bool tf) { this->bmi_var.SetGet(tf); }
    std::string GetName() { return this->bmi_var.GetName(); }
    void SetName(std::string s) { this->bmi_var.SetName(s); }
    bool GetSet() { return this->bmi_var.GetSet(); }
    void SetSet(bool tf) { this->bmi_var.SetSet(tf); }
    std::string GetUnits() { return this->bmi_var.GetUnits(); }
    void SetUnits(std::string s) { this->bmi_var.SetUnits(s); }
    int GetNbytes() { return (int)this->bmi_var.GetNbytes(); }
    void SetNbytes(int n) { this->bmi_var.SetNbytes(n); }
    int GetItemsize() { return this->bmi_var.GetItemsize(); }
    void SetItemsize(int n) { this->bmi_var.SetItemsize(n); }
    std::string GetCType() { return this->bmi_var.GetCType(); }
    void SetCType(std::string s) { this->bmi_var.SetCType(s); }
    std::string GetFType() { return this->bmi_var.GetFType(); }
    void SetFType(std::string s) { this->bmi_var.SetFType(s); }
    std::string GetPType() { return this->bmi_var.GetPType(); }
    void SetPType(std::string s) { this->bmi_var.SetPType(s); }
    void SetTypes(std::string c, std::string f, std::string p)
    {
        this->bmi_var.SetTypes(c, f, p);
    }
    void* GetVoidPtr() { return void_ptr; }
    void SetVoidPtr(void* ptr) { void_ptr = ptr; }
    bool GetHasPtr() { return this->bmi_var.GetHasPtr(); }
    void SetHasPtr(bool tf) { this->bmi_var.SetHasPtr(tf); }

    std::vector<const char*>& GetCharVector() { return CharVector; }
    void SetCharVector(std::vector<const char*> cvec) { CharVector = cvec; }

    void Clear();
};
class IRM_DLL_EXPORT BMIPhreeqcRM : /*public bmi::Bmi,*/ public PhreeqcRM
{
public:
    static void             CleanupBMIModuleInstances(void);
    static int              CreateBMIModule(int nxyz, MP_TYPE nthreads);
    static IRM_RESULT       DestroyBMIModule(int n);
    static BMIPhreeqcRM*    GetInstance(int n);

    BMIPhreeqcRM(int nxyz, int nthreads);
    enum class BMI_TASKS {
        Init,
        Update,
        GetPtr,
        Info,
        GetVar,
        SetVar,
        no_op
    };
    // Model control functions.
    void Initialize(std::string config_file);
    void Update();
    void UpdateUntil(double time);
    void Finalize();

    // Model information functions.
    std::string GetComponentName() {return "BMI PhreeqcRM";};
    int GetInputItemCount();
    int GetOutputItemCount();
    int GetPointableItemCount();
    std::vector<std::string> GetInputVarNames();
    std::vector<std::string> GetOutputVarNames();
    std::vector<std::string> GetPointableVarNames();
    // Variable information functions
    // Not applicable
    int GetVarGrid(const std::string name) {return 1;}
    std::string GetVarType(const std::string name);
    std::string GetVarUnits(const std::string name);
    int GetVarItemsize(const std::string name);
    int GetVarNbytes(const std::string name);
    std::string GetVarLocation(const std::string name) { return "Unknown"; }

    // Time functions
    double GetCurrentTime();
    double GetStartTime();
    double GetEndTime();
    std::string GetTimeUnits() { return "seconds"; };
    //double GetTimeStep(); // already defined in PhreeqcRM

    // Variable getters
    void GetValue(const std::string name, void* dest);
    void GetValue(const std::string name, bool& dest);
    void GetValue(const std::string name, double& dest);
    void GetValue(const std::string name, int& dest);
    void GetValue(const std::string name, std::string& dest);
    void GetValue(const std::string name, std::vector<double>& dest);
    void GetValue(const std::string name, std::vector<int>& dest);
    void GetValue(const std::string name, std::vector<std::string>& dest);
    void* GetValuePtr(std::string name);                  
    void GetValueAtIndices(std::string name, void* dest, int* inds, int count)
    {
        throw NotImplemented();
    };
    
    // Variable setters
    void SetValue(std::string name, void* src);
    void SetValue(std::string name, bool src);
    void SetValue(std::string name, char* src);
    void SetValue(std::string name, double src);
    void SetValue(std::string name, int src);
    void SetValue(std::string name, std::string src);
    void SetValue(std::string name, std::vector<double> src);
    void SetValue(std::string name, std::vector<int>  src);
    void SetValue(std::string name, std::vector<std::string>  src);
    void SetValueAtIndices(std::string name, int* inds, int count, void* src)
    {
        throw NotImplemented();
    };

    // Grid information functions
    // Not implemented
    // PhreeqcRM has no grid 
    int GetGridRank(const int grid);
    int GetGridSize(const int grid);
    std::string GetGridType(const int grid);

    void GetGridShape(const int grid, int* shape)
    {
        throw NotImplemented();
    }
    void GetGridSpacing(const int grid, double* spacing)
    {
        throw NotImplemented();
    }
    void GetGridOrigin(const int grid, double* origin)
    {
        throw NotImplemented();
    }

    void GetGridX(const int grid, double* x)
    {
        throw NotImplemented();
    }
    void GetGridY(const int grid, double* y)
    {
        throw NotImplemented();
    }
    void GetGridZ(const int grid, double* z)
    {
        throw NotImplemented();
    }

    int GetGridNodeCount(const int grid)
    {
        throw NotImplemented();
    }
    int GetGridEdgeCount(const int grid)
    {
        throw NotImplemented();
    }
    int GetGridFaceCount(const int grid)
    {
        throw NotImplemented();
    }

    void GetGridEdgeNodes(const int grid, int* edge_nodes)
    {
        throw NotImplemented();
    }
    void GetGridFaceEdges(const int grid, int* face_edges)
    {
        throw NotImplemented();
    }
    void GetGridFaceNodes(const int grid, int* face_nodes)
    {
        throw NotImplemented();
    }
    void GetGridNodesPerFace(const int grid, int* nodes_per_face)
    {
        throw NotImplemented();
    }
    // data
    BMI_TASKS task;
    BMI_Variant bmi_variant;
    std::string language;
    typedef void (*VarFunction)(BMIPhreeqcRM* brm_ptr); // function pointer type
    typedef std::map<std::string, VarFunction> VarFunction_map;
    VarFunction_map varfn_map;
    VarFunction GetFn(const std::string name);
    std::set<std::string> UpdateMap;
    std::set<std::string> GetUpdateMap() { return UpdateMap; }

private:
    //friend class RM_interface;
    static std::map<size_t, BMIPhreeqcRM*> Instances;
    static size_t InstancesIndex;
    void UpdateVariables();
};
#endif //BMIPHREEQCRM_H_INCLUDED

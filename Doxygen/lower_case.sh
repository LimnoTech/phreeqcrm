#!/bin/sh
export RM_INTERFACE_F90=../src/RM_interface.F90
export YAML_INTERFACE_F90=../src/YAML_interface.F90
# sed -i -e "s/PhreeqcRM/phreeqcrm/g" $RM_INTERFACE_F90
sed -i -e "s/GetGridCellCountYAML/getgridcellcountyaml/g" $RM_INTERFACE_F90
sed -i -e "s/SetGridCellCountYAML/setgridcellcountyaml/g" $RM_INTERFACE_F90
sed -i -e "s/RM_Abort/rm_abort/g" $RM_INTERFACE_F90
sed -i -e "s/RM_CloseFiles/rm_closefiles/g" $RM_INTERFACE_F90
sed -i -e "s/RM_Concentrations2Utility/rm_concentrations2utility/g" $RM_INTERFACE_F90
sed -i -e "s/RM_CreateMapping/rm_createmapping/g" $RM_INTERFACE_F90
sed -i -e "s/RM_Create/rm_create/g" $RM_INTERFACE_F90
sed -i -e "s/RM_DecodeError/rm_decodeerror/g" $RM_INTERFACE_F90
sed -i -e "s/RM_Destroy/rm_destroy/g" $RM_INTERFACE_F90
sed -i -e "s/RM_DumpModule/rm_dumpmodule/g" $RM_INTERFACE_F90
sed -i -e "s/RM_ErrorMessage/rm_errormessage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_FindComponents/rm_findcomponents/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetBackwardMapping/rm_getbackwardmapping/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetChemistryCellCount/rm_getchemistrycellcount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetComponentCount/rm_getcomponentcount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetComponent/rm_getcomponent/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetConcentrations/rm_getconcentrations/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetCurrentSelectedOutputUserNumber/rm_getcurrentselectedoutputusernumber/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetDensityCalculated/rm_getdensitycalculated/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetEndCell/rm_getendcell/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetErrorString/rm_geterrorstring/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetErrorStringLength/rm_geterrorstringlength/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetFilePrefix/rm_getfileprefix/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGasCompMoles/rm_getgascompmoles/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGasCompPhi/rm_getgascompphi/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGasCompPressures/rm_getgascomppressures/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGasPhaseVolume/rm_getgasphasevolume/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGfw/rm_getgfw/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGridCellCount/rm_getgridcellcount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetIPhreeqcId/rm_getiphreeqcid/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetMpiMyself/rm_getmpimyself/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetMpiTasks/rm_getmpitasks/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetNthSelectedOutputUserNumber/rm_getnthselectedoutputusernumber/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetPorosity/rm_getporosity/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetPressure/rm_getpressure/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSaturationCalculated/rm_getsaturationcalculated/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSelectedOutputColumnCount/rm_getselectedoutputcolumncount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSelectedOutputCount/rm_getselectedoutputcount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSelectedOutputHeading/rm_getselectedoutputheading/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSelectedOutputRowCount/rm_getselectedoutputrowcount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSelectedOutput/rm_getselectedoutput/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSolutionVolume/rm_getsolutionvolume/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesConcentrations/rm_getspeciesconcentrations/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesCount/rm_getspeciescount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesD25/rm_getspeciesd25/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesLog10Molalities/rm_getspecieslog10molalities/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesName/rm_getspeciesname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesSaveOn/rm_getspeciessaveon/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesZ/rm_getspeciesz/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetStartCell/rm_getstartcell/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetThreadCount/rm_getthreadcount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetTimeConversion/rm_gettimeconversion/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetTimeStep/rm_gettimestep/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetTime/rm_gettime/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitializeYAML/rm_initializeyaml/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialPhreeqc2Concentrations/rm_initialphreeqc2concentrations/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialPhreeqc2Module/rm_initialphreeqc2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialPhreeqcCell2Module/rm_initialphreeqccell2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialPhreeqc2SpeciesConcentrations/rm_initialphreeqc2speciesconcentrations/g" $RM_INTERFACE_F90
sed -i -e "s/RM_LoadDatabase/rm_loaddatabase/g" $RM_INTERFACE_F90
sed -i -e "s/RM_LogMessage/rm_logmessage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_MpiWorkerBreak/rm_mpiworkerbreak/g" $RM_INTERFACE_F90
sed -i -e "s/RM_MpiWorker/rm_mpiworker/g" $RM_INTERFACE_F90
sed -i -e "s/RM_OpenFiles/rm_openfiles/g" $RM_INTERFACE_F90
sed -i -e "s/RM_OutputMessage/rm_outputmessage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_RunCells/rm_runcells/g" $RM_INTERFACE_F90
sed -i -e "s/RM_RunFile/rm_runfile/g" $RM_INTERFACE_F90
sed -i -e "s/RM_RunString/rm_runstring/g" $RM_INTERFACE_F90
sed -i -e "s/RM_ScreenMessage/rm_screenmessage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetComponentH2O/rm_setcomponenth2o/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetConcentrations/rm_setconcentrations/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetCurrentSelectedOutputUserNumber/rm_setcurrentselectedoutputusernumber/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetDensityUser/rm_setdensityuser/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetDumpFileName/rm_setdumpfilename/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetErrorHandlerMode/rm_seterrorhandlermode/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetErrorOn/rm_seterroron/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetFilePrefix/rm_setfileprefix/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetGasCompMoles/rm_setgascompmoles/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetGasPhaseVolume/rm_setgasphasevolume/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetMpiWorkerCallback/rm_setmpiworkercallback/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetNthSelectedOutput/rm_setnthselectedoutput/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetPartitionUZSolids/rm_setpartitionuzsolids/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetPorosity/rm_setporosity/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetPrintChemistryMask/rm_setprintchemistrymask/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetPrintChemistryOn/rm_setprintchemistryon/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetPressure/rm_setpressure/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetRebalanceFraction/rm_setrebalancefraction/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetRebalanceByCell/rm_setrebalancebycell/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetRepresentativeVolume/rm_setrepresentativevolume/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetSaturationUser/rm_setsaturationuser/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetScreenOn/rm_setscreenon/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetSelectedOutputOn/rm_setselectedoutputon/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetSpeciesSaveOn/rm_setspeciessaveon/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetTemperature/rm_settemperature/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetTimeConversion/rm_settimeconversion/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetTimeStep/rm_settimestep/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetTime/rm_settime/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsExchange/rm_setunitsexchange/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsGasPhase/rm_setunitsgasphase/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsKinetics/rm_setunitskinetics/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsPPassemblage/rm_setunitsppassemblage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsSolution/rm_setunitssolution/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsSSassemblage/rm_setunitsssassemblage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsSSassemblage/rm_setunitsssassemblage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetUnitsSurface/rm_setunitssurface/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SpeciesConcentrations2Module/rm_speciesconcentrations2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_UseSolutionDensityVolume/rm_usesolutiondensityvolume/g" $RM_INTERFACE_F90
sed -i -e "s/RM_WarningMessage/rm_warningmessage/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSpeciesLog10Gammas/rm_getspecieslog10gammas/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetExchangeSpeciesCount/rm_getexchangespeciescount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetExchangeSpeciesName/rm_getexchangespeciesname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetExchangeName/rm_getexchangename/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSurfaceSpeciesCount/rm_getsurfacespeciescount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSurfaceSpeciesName/rm_getsurfacespeciesname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSurfaceType/rm_getsurfacetype/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSurfaceName/rm_getsurfacename/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetEquilibriumPhasesCount/rm_getequilibriumphasescount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetEquilibriumPhasesName/rm_getequilibriumphasesname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGasComponentsCount/rm_getgascomponentscount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGasComponentsName/rm_getgascomponentsname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetKineticReactionsCount/rm_getkineticreactionscount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetKineticReactionsName/rm_getkineticreactionsname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSolidSolutionComponentsCount/rm_getsolidsolutioncomponentscount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSolidSolutionComponentsName/rm_getsolidsolutioncomponentsname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSolidSolutionName/rm_getsolidsolutionname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSICount/rm_getsicount/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSIName/rm_getsiname/g" $RM_INTERFACE_F90
sed -i -e "s/RM_StateSave/rm_statesave/g" $RM_INTERFACE_F90
sed -i -e "s/RM_StateApply/rm_stateapply/g" $RM_INTERFACE_F90
sed -i -e "s/RM_StateDelete/rm_statedelete/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_Finalize/rm_bmi_finalize/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetComponentName/rm_bmi_getcomponentname/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetCurrentTime/rm_bmi_getcurrenttime/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetEndTime/rm_bmi_getendtime/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetInputItemCount/rm_bmi_getinputitemcount/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetInputVarNames/rm_bmi_getinputvarnames/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetOutputItemCount/rm_bmi_getoutputitemcount/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetOutputVarNames/rm_bmi_getoutputvarnames/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetTimeStep/rm_bmi_gettimestep/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetTimeUnits/rm_bmi_gettimeunits/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetValue/rm_bmi_getvalue/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetVarItemsize/rm_bmi_getvaritemsize/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetVarNbytes/rm_bmi_getvarnbytes/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetVarType/rm_bmi_getvartype/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_GetVarUnits/rm_bmi_getvarunits/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_Initialize/rm_bmi_initialize/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_SetValue/rm_bmi_setvalue/g" $RM_INTERFACE_F90
#sed -i -e "s/RM_BMI_Update/rm_bmi_update/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetComponents/rm_getcomponents/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetGridCellCountYAML/rm_getgridcellcountyaml/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetSelectedOutputHeadings/rm_getselectedoutputheadings/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetTemperature/rm_gettemperature/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetViscosity/rm_getviscosity/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetIthConcentration/rm_getithconcentration/g" $RM_INTERFACE_F90
sed -i -e "s/RM_GetIthSpeciesConcentration/rm_getithspeciesconcentration/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetIthConcentration/rm_setithconcentration/g" $RM_INTERFACE_F90
sed -i -e "s/RM_SetIthSpeciesConcentration/rm_setithspeciesconcentration/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialSolutions2Module/rm_initialsolutions2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialEquilibriumPhases2Module/rm_initialequilibriumphases2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialExchanges2Module/rm_initialexchanges2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialSurfaces2Module/rm_initialsurfaces2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialGasPhases2Module/rm_initialgasphases2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialSolidSolutions2Module/rm_initialsolidsolutions2module/g" $RM_INTERFACE_F90
sed -i -e "s/RM_InitialKinetics2Module/rm_initialkinetics2module/g" $RM_INTERFACE_F90
sed -i -e "s/DestroyYAMLPhreeqcRM/destroyyamlphreeqcrm/g" $YAML_INTERFACE_F90
sed -i -e "s/CreateYAMLPhreeqcRM/createyamlphreeqcrm/g" $YAML_INTERFACE_F90
sed -i -e "s/WriteYAMLDoc/writeyamldoc/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLClear/yamlclear/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLCloseFiles/yamlclosefiles/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLCreateMapping/yamlcreatemapping/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLDumpModule/yamldumpmodule/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLFindComponents/yamlfindcomponents/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialSolutions2Module/yamlinitialsolutions2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialEquilibriumPhases2Module/yamlinitialequilibriumphases2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialExchanges2Module/yamlinitialexchanges2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialSurfaces2Module/yamlinitialsurfaces2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialGasPhases2Module/yamlinitialgasphases2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialSolidSolutions2Module/yamlinitialsolidsolutions2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialKinetics2Module/yamlinitialkinetics2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialPhreeqc2Module/yamlinitialphreeqc2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialPhreeqc2Module_mix/yamlinitialphreeqc2module_mix/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLInitialPhreeqcCell2Module/yamlinitialphreeqccell2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLLoadDatabase/yamlloaddatabase/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLLogMessage/yamllogmessage/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLOpenFiles/yamlopenfiles/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLOutputMessage/yamloutputmessage/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLRunCells/yamlruncells/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLRunFile/yamlrunfile/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLRunString/yamlrunstring/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLScreenMessage/yamlscreenmessage/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetComponentH2O/yamlsetcomponenth2o/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetConcentrations/yamlsetconcentrations/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetCurrentSelectedOutputUserNumber/yamlsetcurrentselectedoutputusernumber/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetDensityUser/yamlsetdensityuser/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetDumpFileName/yamlsetdumpfilename/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetErrorHandlerMode/yamlseterrorhandlermode/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetErrorOn/yamlseterroron/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetFilePrefix/yamlsetfileprefix/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetGasCompMoles/yamlsetgascompmoles/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetGasPhaseVolume/yamlsetgasphasevolume/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetGridCellCount/yamlsetgridcellcount/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetNthSelectedOutput/yamlsetnthselectedoutput/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetPartitionUZSolids/yamlsetpartitionuzsolids/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetPorosity/yamlsetporosity/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetPressure/yamlsetpressure/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetPrintChemistryMask/yamlsetprintchemistrymask/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetPrintChemistryOn/yamlsetprintchemistryon/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetRebalanceByCell/yamlsetrebalancebycell/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetRebalanceFraction/yamlsetrebalancefraction/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetRepresentativeVolume/yamlsetrepresentativevolume/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetSaturationUser/yamlsetsaturationuser/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetScreenOn/yamlsetscreenon/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetSelectedOutputOn/yamlsetselectedoutputon/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetSpeciesSaveOn/yamlsetspeciessaveon/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetTemperature/yamlsettemperature/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetTimeConversion/yamlsettimeconversion/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetTimeStep/yamlsettimestep/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetTime/yamlsettime/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetUnitsExchange/yamlsetunitsexchange/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetUnitsGasPhase/yamlsetunitsgasphase/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetUnitsKinetics/yamlsetunitskinetics/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetUnitsPPassemblage/yamlsetunitsppassemblage/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetUnitsSolution/yamlsetunitssolution/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetUnitsSSassemblage/yamlsetunitsssassemblage/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSetUnitsSurface/yamlsetunitssurface/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLSpeciesConcentrations2Module/yamlspeciesconcentrations2module/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLStateSave/yamlstatesave/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLStateApply/yamlstateapply/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLStateDelete/yamlstatedelete/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLUseSolutionDensityVolume/yamlusesolutiondensityvolume/g" $YAML_INTERFACE_F90
sed -i -e "s/YAMLWarningMessage/yamlwarningmessage/g" $YAML_INTERFACE_F90
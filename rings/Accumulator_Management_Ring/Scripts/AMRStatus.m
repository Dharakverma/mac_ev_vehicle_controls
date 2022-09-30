classdef AMRStatus < Simulink.IntEnumType
  enumeration
    Off(0)              %MSR Request, AMR Status
    Off_Pass(1)      	%AMR Status once AMS system ready for StartUp
    Off_Fail(2)         %AMR Status if AMS cannot establish CAN Communication
    
    StartUp(10)         %MSR Request, AMR Status for StartUP WIP
    StartUp_Check(13)   %AMR Status during Fault/Plausibility Check
    StartUp_PreCharge(14)%AMR Status during Precharge Procedure; 
    StartUp_Fail(12)    %AMR Status if StartUp Procedure Fails
    StartUp_Pass(11)    %AMR Status if StartUp Procedure Pass, Ready for Run State
    
    Running(20)         %MSR Request, AMR Status for Run State
    Running_Fail(22)    %AMR Status for failure during Running - will automatically go to Shutdown

    Shutdown(30)        %MSR Request, AMR Status for shutdown WIP
    Shutdown_Fail(32)   %AMR Status for Shutdown Procedure Fails
    Shutdown_Pass(31)   %AMR Status for Shutdown Procedure Pass, Ready for Off State

  end
end 
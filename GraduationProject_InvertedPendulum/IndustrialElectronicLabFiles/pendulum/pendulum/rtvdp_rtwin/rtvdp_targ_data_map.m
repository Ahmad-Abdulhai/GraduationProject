  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData  = 0; %add to this count as we go
    nTotSects = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	;% rtP.Integrator1_IC
	section.data(1).logicalSrcIdx = 0;
	section.data(1).dtTransOffset = 0;
	
	;% rtP.Integrator2_IC
	section.data(2).logicalSrcIdx = 1;
	section.data(2).dtTransOffset = 1;
	
	;% rtP.Saturation_UpperSat
	section.data(3).logicalSrcIdx = 2;
	section.data(3).dtTransOffset = 2;
	
	;% rtP.Saturation_LowerSat
	section.data(4).logicalSrcIdx = 3;
	section.data(4).dtTransOffset = 3;
	
	;% rtP.Mu_Gain
	section.data(5).logicalSrcIdx = 4;
	section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData  = 0; %add to this count as we go
    nTotSects = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	;% rtB.x1
	section.data(1).logicalSrcIdx = 0;
	section.data(1).dtTransOffset = 0;
	
	;% rtB.x2
	section.data(2).logicalSrcIdx = 1;
	section.data(2).dtTransOffset = 1;
	
	;% rtB.Saturation
	section.data(3).logicalSrcIdx = 2;
	section.data(3).dtTransOffset = 2;
	
	;% rtB.Sum
	section.data(4).logicalSrcIdx = 3;
	section.data(4).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1356030225;
  targMap.checksum1 = 55607504;
  targMap.checksum2 = 1788078737;
  targMap.checksum3 = 4222244455;


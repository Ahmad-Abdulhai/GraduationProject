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
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	;% rtP.Read_Cart_Encoder1_P1_Size
	section.data(1).logicalSrcIdx = 0;
	section.data(1).dtTransOffset = 0;
	
	;% rtP.Read_Cart_Encoder1_P1
	section.data(2).logicalSrcIdx = 1;
	section.data(2).dtTransOffset = 2;
	
	;% rtP.Read_Cart_Encoder1_P2_Size
	section.data(3).logicalSrcIdx = 2;
	section.data(3).dtTransOffset = 3;
	
	;% rtP.Read_Cart_Encoder1_P2
	section.data(4).logicalSrcIdx = 3;
	section.data(4).dtTransOffset = 5;
	
	;% rtP.Read_Cart_Encoder1_P3_Size
	section.data(5).logicalSrcIdx = 4;
	section.data(5).dtTransOffset = 6;
	
	;% rtP.Read_Cart_Encoder1_P3
	section.data(6).logicalSrcIdx = 5;
	section.data(6).dtTransOffset = 8;
	
	;% rtP.Read_Cart_Encoder1_P4_Size
	section.data(7).logicalSrcIdx = 6;
	section.data(7).dtTransOffset = 9;
	
	;% rtP.Read_Cart_Encoder1_P4
	section.data(8).logicalSrcIdx = 7;
	section.data(8).dtTransOffset = 11;
	
	;% rtP.Counts_Meters_Gain
	section.data(9).logicalSrcIdx = 8;
	section.data(9).dtTransOffset = 12;
	
	;% rtP.Read_Pendulum_Encoder_P1_Size
	section.data(10).logicalSrcIdx = 9;
	section.data(10).dtTransOffset = 13;
	
	;% rtP.Read_Pendulum_Encoder_P1
	section.data(11).logicalSrcIdx = 10;
	section.data(11).dtTransOffset = 15;
	
	;% rtP.Read_Pendulum_Encoder_P2_Size
	section.data(12).logicalSrcIdx = 11;
	section.data(12).dtTransOffset = 16;
	
	;% rtP.Read_Pendulum_Encoder_P2
	section.data(13).logicalSrcIdx = 12;
	section.data(13).dtTransOffset = 18;
	
	;% rtP.Read_Pendulum_Encoder_P3_Size
	section.data(14).logicalSrcIdx = 13;
	section.data(14).dtTransOffset = 19;
	
	;% rtP.Read_Pendulum_Encoder_P3
	section.data(15).logicalSrcIdx = 14;
	section.data(15).dtTransOffset = 21;
	
	;% rtP.Read_Pendulum_Encoder_P4_Size
	section.data(16).logicalSrcIdx = 15;
	section.data(16).dtTransOffset = 22;
	
	;% rtP.Read_Pendulum_Encoder_P4
	section.data(17).logicalSrcIdx = 16;
	section.data(17).dtTransOffset = 24;
	
	;% rtP.Counts_Radians_Gain
	section.data(18).logicalSrcIdx = 17;
	section.data(18).dtTransOffset = 25;
	
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
      
	;% rtB.Read_Cart_Encoder1
	section.data(1).logicalSrcIdx = 0;
	section.data(1).dtTransOffset = 0;
	
	;% rtB.Cart_Position
	section.data(2).logicalSrcIdx = 1;
	section.data(2).dtTransOffset = 1;
	
	;% rtB.Read_Pendulum_Encoder
	section.data(3).logicalSrcIdx = 2;
	section.data(3).dtTransOffset = 2;
	
	;% rtB.Pendulum_Position
	section.data(4).logicalSrcIdx = 3;
	section.data(4).dtTransOffset = 3;
	
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


  targMap.checksum0 = 3988474959;
  targMap.checksum1 = 1196956938;
  targMap.checksum2 = 2467882105;
  targMap.checksum3 = 2395496463;


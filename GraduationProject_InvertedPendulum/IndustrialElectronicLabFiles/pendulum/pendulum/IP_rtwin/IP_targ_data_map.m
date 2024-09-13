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
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
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
	
	;% rtP.Step_Time
	section.data(19).logicalSrcIdx = 18;
	section.data(19).dtTransOffset = 26;
	
	;% rtP.Step_Y0
	section.data(20).logicalSrcIdx = 19;
	section.data(20).dtTransOffset = 27;
	
	;% rtP.Step_YFinal
	section.data(21).logicalSrcIdx = 20;
	section.data(21).dtTransOffset = 28;
	
	;% rtP.Step1_Time
	section.data(22).logicalSrcIdx = 21;
	section.data(22).dtTransOffset = 29;
	
	;% rtP.Step1_Y0
	section.data(23).logicalSrcIdx = 22;
	section.data(23).dtTransOffset = 30;
	
	;% rtP.Step1_YFinal
	section.data(24).logicalSrcIdx = 23;
	section.data(24).dtTransOffset = 31;
	
	;% rtP.Digital_To_Analog_Convert_P1_Si
	section.data(25).logicalSrcIdx = 24;
	section.data(25).dtTransOffset = 32;
	
	;% rtP.Digital_To_Analog_Convert_P1
	section.data(26).logicalSrcIdx = 25;
	section.data(26).dtTransOffset = 34;
	
	;% rtP.Digital_To_Analog_Convert_P2_Si
	section.data(27).logicalSrcIdx = 26;
	section.data(27).dtTransOffset = 35;
	
	;% rtP.Digital_To_Analog_Convert_P2
	section.data(28).logicalSrcIdx = 27;
	section.data(28).dtTransOffset = 37;
	
	;% rtP.Digital_To_Analog_Convert_P3_Si
	section.data(29).logicalSrcIdx = 28;
	section.data(29).dtTransOffset = 38;
	
	;% rtP.Digital_To_Analog_Convert_P3
	section.data(30).logicalSrcIdx = 29;
	section.data(30).dtTransOffset = 40;
	
	;% rtP.Digital_To_Analog_Convert_P4_Si
	section.data(31).logicalSrcIdx = 30;
	section.data(31).dtTransOffset = 41;
	
	;% rtP.Digital_To_Analog_Convert_P4
	section.data(32).logicalSrcIdx = 31;
	section.data(32).dtTransOffset = 43;
	
	;% rtP.Scaling_Gain
	section.data(33).logicalSrcIdx = 32;
	section.data(33).dtTransOffset = 44;
	
	;% rtP.Saturation_UpperSat
	section.data(34).logicalSrcIdx = 33;
	section.data(34).dtTransOffset = 45;
	
	;% rtP.Saturation_LowerSat
	section.data(35).logicalSrcIdx = 34;
	section.data(35).dtTransOffset = 46;
	
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
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
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
	
	;% rtB.Sum
	section.data(5).logicalSrcIdx = 4;
	section.data(5).dtTransOffset = 4;
	
	;% rtB.Clock
	section.data(6).logicalSrcIdx = 5;
	section.data(6).dtTransOffset = 5;
	
	;% rtB.Saturation
	section.data(7).logicalSrcIdx = 6;
	section.data(7).dtTransOffset = 6;
	
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


  targMap.checksum0 = 3703030922;
  targMap.checksum1 = 2102414408;
  targMap.checksum2 = 379343534;
  targMap.checksum3 = 228345626;


  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData  = 0; %add to this count as we go
    nTotSects = 2;
    
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
      section.nData     = 49;
      section.data(49)  = dumData; %prealloc
      
	;% rtP.Digital_To_Analog_Convert_P1_Si
	section.data(1).logicalSrcIdx = 0;
	section.data(1).dtTransOffset = 0;
	
	;% rtP.Digital_To_Analog_Convert_P1
	section.data(2).logicalSrcIdx = 1;
	section.data(2).dtTransOffset = 2;
	
	;% rtP.Digital_To_Analog_Convert_P2_Si
	section.data(3).logicalSrcIdx = 2;
	section.data(3).dtTransOffset = 3;
	
	;% rtP.Digital_To_Analog_Convert_P2
	section.data(4).logicalSrcIdx = 3;
	section.data(4).dtTransOffset = 5;
	
	;% rtP.Digital_To_Analog_Convert_P3_Si
	section.data(5).logicalSrcIdx = 4;
	section.data(5).dtTransOffset = 6;
	
	;% rtP.Digital_To_Analog_Convert_P3
	section.data(6).logicalSrcIdx = 5;
	section.data(6).dtTransOffset = 8;
	
	;% rtP.Digital_To_Analog_Convert_P4_Si
	section.data(7).logicalSrcIdx = 6;
	section.data(7).dtTransOffset = 9;
	
	;% rtP.Digital_To_Analog_Convert_P4
	section.data(8).logicalSrcIdx = 7;
	section.data(8).dtTransOffset = 11;
	
	;% rtP.Read_Cart_Encoder1_P1_Size
	section.data(9).logicalSrcIdx = 8;
	section.data(9).dtTransOffset = 12;
	
	;% rtP.Read_Cart_Encoder1_P1
	section.data(10).logicalSrcIdx = 9;
	section.data(10).dtTransOffset = 14;
	
	;% rtP.Read_Cart_Encoder1_P2_Size
	section.data(11).logicalSrcIdx = 10;
	section.data(11).dtTransOffset = 15;
	
	;% rtP.Read_Cart_Encoder1_P2
	section.data(12).logicalSrcIdx = 11;
	section.data(12).dtTransOffset = 17;
	
	;% rtP.Read_Cart_Encoder1_P3_Size
	section.data(13).logicalSrcIdx = 12;
	section.data(13).dtTransOffset = 18;
	
	;% rtP.Read_Cart_Encoder1_P3
	section.data(14).logicalSrcIdx = 13;
	section.data(14).dtTransOffset = 20;
	
	;% rtP.Read_Cart_Encoder1_P4_Size
	section.data(15).logicalSrcIdx = 14;
	section.data(15).dtTransOffset = 21;
	
	;% rtP.Read_Cart_Encoder1_P4
	section.data(16).logicalSrcIdx = 15;
	section.data(16).dtTransOffset = 23;
	
	;% rtP.Counts_Meters_Gain
	section.data(17).logicalSrcIdx = 16;
	section.data(17).dtTransOffset = 24;
	
	;% rtP.Step_Time
	section.data(18).logicalSrcIdx = 17;
	section.data(18).dtTransOffset = 25;
	
	;% rtP.Step_Y0
	section.data(19).logicalSrcIdx = 18;
	section.data(19).dtTransOffset = 26;
	
	;% rtP.Step_YFinal
	section.data(20).logicalSrcIdx = 19;
	section.data(20).dtTransOffset = 27;
	
	;% rtP.Cart_Velocity_Filter_A
	section.data(21).logicalSrcIdx = 20;
	section.data(21).dtTransOffset = 28;
	
	;% rtP.Cart_Velocity_Filter_C
	section.data(22).logicalSrcIdx = 21;
	section.data(22).dtTransOffset = 30;
	
	;% rtP.Read_Pendulum_Encoder_P1_Size
	section.data(23).logicalSrcIdx = 24;
	section.data(23).dtTransOffset = 32;
	
	;% rtP.Read_Pendulum_Encoder_P1
	section.data(24).logicalSrcIdx = 25;
	section.data(24).dtTransOffset = 34;
	
	;% rtP.Read_Pendulum_Encoder_P2_Size
	section.data(25).logicalSrcIdx = 26;
	section.data(25).dtTransOffset = 35;
	
	;% rtP.Read_Pendulum_Encoder_P2
	section.data(26).logicalSrcIdx = 27;
	section.data(26).dtTransOffset = 37;
	
	;% rtP.Read_Pendulum_Encoder_P3_Size
	section.data(27).logicalSrcIdx = 28;
	section.data(27).dtTransOffset = 38;
	
	;% rtP.Read_Pendulum_Encoder_P3
	section.data(28).logicalSrcIdx = 29;
	section.data(28).dtTransOffset = 40;
	
	;% rtP.Read_Pendulum_Encoder_P4_Size
	section.data(29).logicalSrcIdx = 30;
	section.data(29).dtTransOffset = 41;
	
	;% rtP.Read_Pendulum_Encoder_P4
	section.data(30).logicalSrcIdx = 31;
	section.data(30).dtTransOffset = 43;
	
	;% rtP.Counts_Radians_Gain
	section.data(31).logicalSrcIdx = 32;
	section.data(31).dtTransOffset = 44;
	
	;% rtP.Pendulum_Velocity_Filter_A
	section.data(32).logicalSrcIdx = 33;
	section.data(32).dtTransOffset = 45;
	
	;% rtP.Pendulum_Velocity_Filter_C
	section.data(33).logicalSrcIdx = 34;
	section.data(33).dtTransOffset = 47;
	
	;% rtP.Constant1_Value
	section.data(34).logicalSrcIdx = 37;
	section.data(34).dtTransOffset = 49;
	
	;% rtP.Constant2_Value
	section.data(35).logicalSrcIdx = 38;
	section.data(35).dtTransOffset = 50;
	
	;% rtP.Constant3_Value
	section.data(36).logicalSrcIdx = 39;
	section.data(36).dtTransOffset = 51;
	
	;% rtP.Look_Up_Table_n_D_tableData
	section.data(37).logicalSrcIdx = 40;
	section.data(37).dtTransOffset = 52;
	
	;% rtP.Look_Up_Table_n_D_bp01Data
	section.data(38).logicalSrcIdx = 41;
	section.data(38).dtTransOffset = 6613;
	
	;% rtP.Look_Up_Table_n_D_bp02Data
	section.data(39).logicalSrcIdx = 42;
	section.data(39).dtTransOffset = 6694;
	
	;% rtP.Gain2_a_Gain
	section.data(40).logicalSrcIdx = 43;
	section.data(40).dtTransOffset = 6775;
	
	;% rtP.Memory_a_X0
	section.data(41).logicalSrcIdx = 44;
	section.data(41).dtTransOffset = 6776;
	
	;% rtP.fuzzy_Look_Up_tableData
	section.data(42).logicalSrcIdx = 45;
	section.data(42).dtTransOffset = 6777;
	
	;% rtP.fuzzy_Look_Up_bp01Data
	section.data(43).logicalSrcIdx = 46;
	section.data(43).dtTransOffset = 13338;
	
	;% rtP.fuzzy_Look_Up_bp02Data
	section.data(44).logicalSrcIdx = 47;
	section.data(44).dtTransOffset = 13419;
	
	;% rtP.Gain2_b_Gain
	section.data(45).logicalSrcIdx = 48;
	section.data(45).dtTransOffset = 13500;
	
	;% rtP.Memory_b_X0
	section.data(46).logicalSrcIdx = 49;
	section.data(46).dtTransOffset = 13501;
	
	;% rtP.Scaling_Gain
	section.data(47).logicalSrcIdx = 50;
	section.data(47).dtTransOffset = 13502;
	
	;% rtP.Saturation_UpperSat
	section.data(48).logicalSrcIdx = 51;
	section.data(48).dtTransOffset = 13503;
	
	;% rtP.Saturation_LowerSat
	section.data(49).logicalSrcIdx = 52;
	section.data(49).dtTransOffset = 13504;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	;% rtP.Look_Up_Table_n_D_maxIndex
	section.data(1).logicalSrcIdx = 53;
	section.data(1).dtTransOffset = 0;
	
	;% rtP.fuzzy_Look_Up_maxIndex
	section.data(2).logicalSrcIdx = 54;
	section.data(2).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
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
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	;% rtB.Read_Cart_Encoder1
	section.data(1).logicalSrcIdx = 0;
	section.data(1).dtTransOffset = 0;
	
	;% rtB.Cart_Position
	section.data(2).logicalSrcIdx = 1;
	section.data(2).dtTransOffset = 1;
	
	;% rtB.Desired_Position
	section.data(3).logicalSrcIdx = 2;
	section.data(3).dtTransOffset = 2;
	
	;% rtB.Cart_Velocity
	section.data(4).logicalSrcIdx = 3;
	section.data(4).dtTransOffset = 3;
	
	;% rtB.Read_Pendulum_Encoder
	section.data(5).logicalSrcIdx = 4;
	section.data(5).dtTransOffset = 4;
	
	;% rtB.Pendulum_Position
	section.data(6).logicalSrcIdx = 5;
	section.data(6).dtTransOffset = 5;
	
	;% rtB.Pendulum_Velocity
	section.data(7).logicalSrcIdx = 6;
	section.data(7).dtTransOffset = 6;
	
	;% rtB.derCartPos
	section.data(8).logicalSrcIdx = 7;
	section.data(8).dtTransOffset = 7;
	
	;% rtB.Look_Up_Table_n_D
	section.data(9).logicalSrcIdx = 8;
	section.data(9).dtTransOffset = 8;
	
	;% rtB.Memory_a
	section.data(10).logicalSrcIdx = 9;
	section.data(10).dtTransOffset = 9;
	
	;% rtB.fuzzy_Look_Up
	section.data(11).logicalSrcIdx = 10;
	section.data(11).dtTransOffset = 10;
	
	;% rtB.Memory_b
	section.data(12).logicalSrcIdx = 11;
	section.data(12).dtTransOffset = 11;
	
	;% rtB.derPendPos
	section.data(13).logicalSrcIdx = 12;
	section.data(13).dtTransOffset = 12;
	
	;% rtB.Saturation
	section.data(14).logicalSrcIdx = 13;
	section.data(14).dtTransOffset = 13;
	
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


  targMap.checksum0 = 4086371691;
  targMap.checksum1 = 1795036303;
  targMap.checksum2 = 1292260853;
  targMap.checksum3 = 196811862;


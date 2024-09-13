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
      section.nData     = 52;
      section.data(52)  = dumData; %prealloc
      
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
	
	;% rtP.Desired_Position_Input_Amp
	section.data(9).logicalSrcIdx = 8;
	section.data(9).dtTransOffset = 12;
	
	;% rtP.Desired_Position_Input_Bias
	section.data(10).logicalSrcIdx = 9;
	section.data(10).dtTransOffset = 13;
	
	;% rtP.Desired_Position_Input_Freq
	section.data(11).logicalSrcIdx = 10;
	section.data(11).dtTransOffset = 14;
	
	;% rtP.Desired_Position_Input_Phase
	section.data(12).logicalSrcIdx = 11;
	section.data(12).dtTransOffset = 15;
	
	;% rtP.Read_Cart_Encoder_P1_Size
	section.data(13).logicalSrcIdx = 12;
	section.data(13).dtTransOffset = 16;
	
	;% rtP.Read_Cart_Encoder_P1
	section.data(14).logicalSrcIdx = 13;
	section.data(14).dtTransOffset = 18;
	
	;% rtP.Read_Cart_Encoder_P2_Size
	section.data(15).logicalSrcIdx = 14;
	section.data(15).dtTransOffset = 19;
	
	;% rtP.Read_Cart_Encoder_P2
	section.data(16).logicalSrcIdx = 15;
	section.data(16).dtTransOffset = 21;
	
	;% rtP.Read_Cart_Encoder_P3_Size
	section.data(17).logicalSrcIdx = 16;
	section.data(17).dtTransOffset = 22;
	
	;% rtP.Read_Cart_Encoder_P3
	section.data(18).logicalSrcIdx = 17;
	section.data(18).dtTransOffset = 24;
	
	;% rtP.Read_Cart_Encoder_P4_Size
	section.data(19).logicalSrcIdx = 18;
	section.data(19).dtTransOffset = 25;
	
	;% rtP.Read_Cart_Encoder_P4
	section.data(20).logicalSrcIdx = 19;
	section.data(20).dtTransOffset = 27;
	
	;% rtP.Counts_Meters_Gain
	section.data(21).logicalSrcIdx = 20;
	section.data(21).dtTransOffset = 28;
	
	;% rtP.Proportional_a_Gain
	section.data(22).logicalSrcIdx = 21;
	section.data(22).dtTransOffset = 29;
	
	;% rtP.Integral_a_A
	section.data(23).logicalSrcIdx = 22;
	section.data(23).dtTransOffset = 30;
	
	;% rtP.Integral_a_C
	section.data(24).logicalSrcIdx = 23;
	section.data(24).dtTransOffset = 31;
	
	;% rtP.Cart_Velocity_Filter1_A
	section.data(25).logicalSrcIdx = 26;
	section.data(25).dtTransOffset = 32;
	
	;% rtP.Cart_Velocity_Filter1_C
	section.data(26).logicalSrcIdx = 27;
	section.data(26).dtTransOffset = 34;
	
	;% rtP.Read_Pendulum_Encoder_P1_Size
	section.data(27).logicalSrcIdx = 30;
	section.data(27).dtTransOffset = 36;
	
	;% rtP.Read_Pendulum_Encoder_P1
	section.data(28).logicalSrcIdx = 31;
	section.data(28).dtTransOffset = 38;
	
	;% rtP.Read_Pendulum_Encoder_P2_Size
	section.data(29).logicalSrcIdx = 32;
	section.data(29).dtTransOffset = 39;
	
	;% rtP.Read_Pendulum_Encoder_P2
	section.data(30).logicalSrcIdx = 33;
	section.data(30).dtTransOffset = 41;
	
	;% rtP.Read_Pendulum_Encoder_P3_Size
	section.data(31).logicalSrcIdx = 34;
	section.data(31).dtTransOffset = 42;
	
	;% rtP.Read_Pendulum_Encoder_P3
	section.data(32).logicalSrcIdx = 35;
	section.data(32).dtTransOffset = 44;
	
	;% rtP.Read_Pendulum_Encoder_P4_Size
	section.data(33).logicalSrcIdx = 36;
	section.data(33).dtTransOffset = 45;
	
	;% rtP.Read_Pendulum_Encoder_P4
	section.data(34).logicalSrcIdx = 37;
	section.data(34).dtTransOffset = 47;
	
	;% rtP.Counts_Radians_Gain
	section.data(35).logicalSrcIdx = 38;
	section.data(35).dtTransOffset = 48;
	
	;% rtP.s7_Value
	section.data(36).logicalSrcIdx = 39;
	section.data(36).dtTransOffset = 49;
	
	;% rtP.Proportional_b_Gain
	section.data(37).logicalSrcIdx = 40;
	section.data(37).dtTransOffset = 50;
	
	;% rtP.Integral_b_A
	section.data(38).logicalSrcIdx = 41;
	section.data(38).dtTransOffset = 51;
	
	;% rtP.Integral_b_C
	section.data(39).logicalSrcIdx = 42;
	section.data(39).dtTransOffset = 52;
	
	;% rtP.Pendulum_Velocity_Filter_A
	section.data(40).logicalSrcIdx = 45;
	section.data(40).dtTransOffset = 53;
	
	;% rtP.Pendulum_Velocity_Filter_C
	section.data(41).logicalSrcIdx = 46;
	section.data(41).dtTransOffset = 55;
	
	;% rtP.Cart_Velocity_Filter_A
	section.data(42).logicalSrcIdx = 49;
	section.data(42).dtTransOffset = 57;
	
	;% rtP.Cart_Velocity_Filter_C
	section.data(43).logicalSrcIdx = 50;
	section.data(43).dtTransOffset = 59;
	
	;% rtP.id_Threshold
	section.data(44).logicalSrcIdx = 53;
	section.data(44).dtTransOffset = 61;
	
	;% rtP.Gain_Gain
	section.data(45).logicalSrcIdx = 54;
	section.data(45).dtTransOffset = 62;
	
	;% rtP.Saturation_UpperSat
	section.data(46).logicalSrcIdx = 55;
	section.data(46).dtTransOffset = 63;
	
	;% rtP.Saturation_LowerSat
	section.data(47).logicalSrcIdx = 56;
	section.data(47).dtTransOffset = 64;
	
	;% rtP.Plot_Scaling_Gain
	section.data(48).logicalSrcIdx = 57;
	section.data(48).dtTransOffset = 65;
	
	;% rtP.D_a_Gain
	section.data(49).logicalSrcIdx = 58;
	section.data(49).dtTransOffset = 66;
	
	;% rtP.D_b_Gain
	section.data(50).logicalSrcIdx = 59;
	section.data(50).dtTransOffset = 67;
	
	;% rtP.Gain2_Gain
	section.data(51).logicalSrcIdx = 60;
	section.data(51).dtTransOffset = 68;
	
	;% rtP.Gain3_Gain
	section.data(52).logicalSrcIdx = 61;
	section.data(52).dtTransOffset = 69;
	
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
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	;% rtB.Desired_Position
	section.data(1).logicalSrcIdx = 0;
	section.data(1).dtTransOffset = 0;
	
	;% rtB.Read_Cart_Encoder
	section.data(2).logicalSrcIdx = 1;
	section.data(2).dtTransOffset = 1;
	
	;% rtB.actual_CartPosition
	section.data(3).logicalSrcIdx = 2;
	section.data(3).dtTransOffset = 2;
	
	;% rtB.Sum2
	section.data(4).logicalSrcIdx = 3;
	section.data(4).dtTransOffset = 3;
	
	;% rtB.Read_Pendulum_Encoder
	section.data(5).logicalSrcIdx = 4;
	section.data(5).dtTransOffset = 4;
	
	;% rtB.Sum3
	section.data(6).logicalSrcIdx = 5;
	section.data(6).dtTransOffset = 5;
	
	;% rtB.Proportional_b
	section.data(7).logicalSrcIdx = 6;
	section.data(7).dtTransOffset = 6;
	
	;% rtB.Saturation
	section.data(8).logicalSrcIdx = 7;
	section.data(8).dtTransOffset = 7;
	
	;% rtB.Pendulum_Angle_Deviation_from_E
	section.data(9).logicalSrcIdx = 8;
	section.data(9).dtTransOffset = 8;
	
	;% rtB.derPendPos
	section.data(10).logicalSrcIdx = 9;
	section.data(10).dtTransOffset = 9;
	
	;% rtB.D_a
	section.data(11).logicalSrcIdx = 10;
	section.data(11).dtTransOffset = 10;
	
	;% rtB.Derivative_a
	section.data(12).logicalSrcIdx = 11;
	section.data(12).dtTransOffset = 11;
	
	;% rtB.D_b
	section.data(13).logicalSrcIdx = 12;
	section.data(13).dtTransOffset = 12;
	
	;% rtB.Derivative_b
	section.data(14).logicalSrcIdx = 13;
	section.data(14).dtTransOffset = 13;
	
	;% rtB.Gain3
	section.data(15).logicalSrcIdx = 14;
	section.data(15).dtTransOffset = 14;
	
	;% rtB.Gain2
	section.data(16).logicalSrcIdx = 15;
	section.data(16).dtTransOffset = 15;
	
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


  targMap.checksum0 = 2290999061;
  targMap.checksum1 = 744840901;
  targMap.checksum2 = 952558526;
  targMap.checksum3 = 2458867920;


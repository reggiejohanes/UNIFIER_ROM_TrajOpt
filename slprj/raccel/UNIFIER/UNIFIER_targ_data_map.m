    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 28;
        sectIdxOffset = 0;

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
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.dp_VTAIL
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.dp_VTAIL_INDUCED
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.dp_WING_root
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.dp_WING_tip
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.dp_DEP
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.dp_HTU
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.dp_FUSE_FIN
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtP.DEP_INTEG_IC
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.DEP_PID_IC
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Euler0
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.I
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 5;

                    ;% rtP.S
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 14;

                    ;% rtP.Vb0
                    section.data(6).logicalSrcIdx = 12;
                    section.data(6).dtTransOffset = 15;

                    ;% rtP.Xe0
                    section.data(7).logicalSrcIdx = 13;
                    section.data(7).dtTransOffset = 18;

                    ;% rtP.ground_alt
                    section.data(8).logicalSrcIdx = 14;
                    section.data(8).dtTransOffset = 21;

                    ;% rtP.latlong0
                    section.data(9).logicalSrcIdx = 15;
                    section.data(9).dtTransOffset = 22;

                    ;% rtP.m
                    section.data(10).logicalSrcIdx = 16;
                    section.data(10).dtTransOffset = 24;

                    ;% rtP.omegab0
                    section.data(11).logicalSrcIdx = 17;
                    section.data(11).dtTransOffset = 25;

                    ;% rtP.u1_0
                    section.data(12).logicalSrcIdx = 18;
                    section.data(12).dtTransOffset = 28;

                    ;% rtP.u2_0
                    section.data(13).logicalSrcIdx = 19;
                    section.data(13).dtTransOffset = 34;

                    ;% rtP.u3_0
                    section.data(14).logicalSrcIdx = 20;
                    section.data(14).dtTransOffset = 46;

                    ;% rtP.u4_0
                    section.data(15).logicalSrcIdx = 21;
                    section.data(15).dtTransOffset = 47;

                    ;% rtP.vtail_dist_to_wing
                    section.data(16).logicalSrcIdx = 22;
                    section.data(16).dtTransOffset = 48;

                    ;% rtP.xyz_DEP
                    section.data(17).logicalSrcIdx = 23;
                    section.data(17).dtTransOffset = 49;

                    ;% rtP.xyz_cg
                    section.data(18).logicalSrcIdx = 24;
                    section.data(18).dtTransOffset = 85;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtP.vtail_nodes
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.wing_nodes
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 50;
            section.data(50)  = dumData; %prealloc

                    ;% rtP.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.CompareToConstant_const_i014zkpdcc
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.CompareToConstant_const_jqmuxowg3j
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.CompareToConstant_const_b5kwy5yvv2
                    section.data(4).logicalSrcIdx = 30;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.CompareToConstant_const_j3nekrd5nd
                    section.data(5).logicalSrcIdx = 31;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.CompareToConstant_const_gvfea0moje
                    section.data(6).logicalSrcIdx = 32;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Distanceintogustx_d_m
                    section.data(7).logicalSrcIdx = 33;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.Distanceintogusty_d_m
                    section.data(8).logicalSrcIdx = 34;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.Distanceintogustz_d_m
                    section.data(9).logicalSrcIdx = 35;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.DiscreteWindGustModel1_d_m
                    section.data(10).logicalSrcIdx = 36;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.LinearSecondOrderActuator_fin_act_0
                    section.data(11).logicalSrcIdx = 37;
                    section.data(11).dtTransOffset = 12;

                    ;% rtP.LinearSecondOrderActuator_fin_act_0_mm13zzlfoj
                    section.data(12).logicalSrcIdx = 38;
                    section.data(12).dtTransOffset = 13;

                    ;% rtP.LinearSecondOrderActuator1_fin_act_0
                    section.data(13).logicalSrcIdx = 39;
                    section.data(13).dtTransOffset = 19;

                    ;% rtP.LinearSecondOrderActuator2_fin_act_0
                    section.data(14).logicalSrcIdx = 40;
                    section.data(14).dtTransOffset = 25;

                    ;% rtP.LinearSecondOrderActuator4_fin_act_0
                    section.data(15).logicalSrcIdx = 41;
                    section.data(15).dtTransOffset = 31;

                    ;% rtP.LinearSecondOrderActuator5_fin_act_0
                    section.data(16).logicalSrcIdx = 42;
                    section.data(16).dtTransOffset = 32;

                    ;% rtP.LinearSecondOrderActuator6_fin_act_0
                    section.data(17).logicalSrcIdx = 43;
                    section.data(17).dtTransOffset = 33;

                    ;% rtP.LinearSecondOrderActuator_fin_act_vel
                    section.data(18).logicalSrcIdx = 44;
                    section.data(18).dtTransOffset = 34;

                    ;% rtP.LinearSecondOrderActuator_fin_act_vel_ddjzhl2ptw
                    section.data(19).logicalSrcIdx = 45;
                    section.data(19).dtTransOffset = 35;

                    ;% rtP.LinearSecondOrderActuator1_fin_act_vel
                    section.data(20).logicalSrcIdx = 46;
                    section.data(20).dtTransOffset = 36;

                    ;% rtP.LinearSecondOrderActuator2_fin_act_vel
                    section.data(21).logicalSrcIdx = 47;
                    section.data(21).dtTransOffset = 37;

                    ;% rtP.LinearSecondOrderActuator3_fin_act_vel
                    section.data(22).logicalSrcIdx = 48;
                    section.data(22).dtTransOffset = 38;

                    ;% rtP.LinearSecondOrderActuator4_fin_act_vel
                    section.data(23).logicalSrcIdx = 49;
                    section.data(23).dtTransOffset = 39;

                    ;% rtP.LinearSecondOrderActuator5_fin_act_vel
                    section.data(24).logicalSrcIdx = 50;
                    section.data(24).dtTransOffset = 40;

                    ;% rtP.LinearSecondOrderActuator6_fin_act_vel
                    section.data(25).logicalSrcIdx = 51;
                    section.data(25).dtTransOffset = 41;

                    ;% rtP.LinearSecondOrderActuator7_fin_act_vel
                    section.data(26).logicalSrcIdx = 52;
                    section.data(26).dtTransOffset = 42;

                    ;% rtP.LinearSecondOrderActuator8_fin_act_vel
                    section.data(27).logicalSrcIdx = 53;
                    section.data(27).dtTransOffset = 43;

                    ;% rtP.FlatEarthtoLLA_psi
                    section.data(28).logicalSrcIdx = 54;
                    section.data(28).dtTransOffset = 44;

                    ;% rtP.DiscreteWindGustModel1_t_0
                    section.data(29).logicalSrcIdx = 55;
                    section.data(29).dtTransOffset = 45;

                    ;% rtP.DiscreteWindGustModel1_v_m
                    section.data(30).logicalSrcIdx = 56;
                    section.data(30).dtTransOffset = 46;

                    ;% rtP.LinearSecondOrderActuator_wn_fin
                    section.data(31).logicalSrcIdx = 57;
                    section.data(31).dtTransOffset = 49;

                    ;% rtP.LinearSecondOrderActuator_wn_fin_ilmnm2ylbj
                    section.data(32).logicalSrcIdx = 58;
                    section.data(32).dtTransOffset = 50;

                    ;% rtP.LinearSecondOrderActuator1_wn_fin
                    section.data(33).logicalSrcIdx = 59;
                    section.data(33).dtTransOffset = 51;

                    ;% rtP.LinearSecondOrderActuator2_wn_fin
                    section.data(34).logicalSrcIdx = 60;
                    section.data(34).dtTransOffset = 52;

                    ;% rtP.LinearSecondOrderActuator3_wn_fin
                    section.data(35).logicalSrcIdx = 61;
                    section.data(35).dtTransOffset = 53;

                    ;% rtP.LinearSecondOrderActuator4_wn_fin
                    section.data(36).logicalSrcIdx = 62;
                    section.data(36).dtTransOffset = 54;

                    ;% rtP.LinearSecondOrderActuator5_wn_fin
                    section.data(37).logicalSrcIdx = 63;
                    section.data(37).dtTransOffset = 55;

                    ;% rtP.LinearSecondOrderActuator6_wn_fin
                    section.data(38).logicalSrcIdx = 64;
                    section.data(38).dtTransOffset = 56;

                    ;% rtP.LinearSecondOrderActuator7_wn_fin
                    section.data(39).logicalSrcIdx = 65;
                    section.data(39).dtTransOffset = 57;

                    ;% rtP.LinearSecondOrderActuator8_wn_fin
                    section.data(40).logicalSrcIdx = 66;
                    section.data(40).dtTransOffset = 58;

                    ;% rtP.LinearSecondOrderActuator_z_fin
                    section.data(41).logicalSrcIdx = 67;
                    section.data(41).dtTransOffset = 59;

                    ;% rtP.LinearSecondOrderActuator_z_fin_ag5smfntgf
                    section.data(42).logicalSrcIdx = 68;
                    section.data(42).dtTransOffset = 60;

                    ;% rtP.LinearSecondOrderActuator1_z_fin
                    section.data(43).logicalSrcIdx = 69;
                    section.data(43).dtTransOffset = 61;

                    ;% rtP.LinearSecondOrderActuator2_z_fin
                    section.data(44).logicalSrcIdx = 70;
                    section.data(44).dtTransOffset = 62;

                    ;% rtP.LinearSecondOrderActuator3_z_fin
                    section.data(45).logicalSrcIdx = 71;
                    section.data(45).dtTransOffset = 63;

                    ;% rtP.LinearSecondOrderActuator4_z_fin
                    section.data(46).logicalSrcIdx = 72;
                    section.data(46).dtTransOffset = 64;

                    ;% rtP.LinearSecondOrderActuator5_z_fin
                    section.data(47).logicalSrcIdx = 73;
                    section.data(47).dtTransOffset = 65;

                    ;% rtP.LinearSecondOrderActuator6_z_fin
                    section.data(48).logicalSrcIdx = 74;
                    section.data(48).dtTransOffset = 66;

                    ;% rtP.LinearSecondOrderActuator7_z_fin
                    section.data(49).logicalSrcIdx = 75;
                    section.data(49).dtTransOffset = 67;

                    ;% rtP.LinearSecondOrderActuator8_z_fin
                    section.data(50).logicalSrcIdx = 76;
                    section.data(50).dtTransOffset = 68;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 15;
            section.data(15)  = dumData; %prealloc

                    ;% rtP.UDPSend1_remotePort
                    section.data(1).logicalSrcIdx = 77;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.UDPSend1_remotePort_ardthcndv5
                    section.data(2).logicalSrcIdx = 78;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.UDPSend_remotePort
                    section.data(3).logicalSrcIdx = 79;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.UDPSend1_remotePort_fttrxcefev
                    section.data(4).logicalSrcIdx = 80;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.UDPSend1_remotePort_eq52r0avzy
                    section.data(5).logicalSrcIdx = 81;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.UDPSend1_remotePort_jffxhvsqzl
                    section.data(6).logicalSrcIdx = 82;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.UDPSend1_remotePort_ijqt2smdg0
                    section.data(7).logicalSrcIdx = 83;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.UDPSend1_remotePort_ocmwsta0fc
                    section.data(8).logicalSrcIdx = 84;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.UDPSend1_remotePort_lq3erkca52
                    section.data(9).logicalSrcIdx = 85;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.UDPSend1_remotePort_eimzoxna1i
                    section.data(10).logicalSrcIdx = 86;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.UDPSend1_remotePort_ni5g4d2iss
                    section.data(11).logicalSrcIdx = 87;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.UDPSend1_remotePort_azm1mqpelq
                    section.data(12).logicalSrcIdx = 88;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.UDPSend1_remotePort_dt0jkdmcmg
                    section.data(13).logicalSrcIdx = 89;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.UDPSend1_remotePort_bao1nst35q
                    section.data(14).logicalSrcIdx = 90;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.UDPSend1_remotePort_edlmksw0fl
                    section.data(15).logicalSrcIdx = 91;
                    section.data(15).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtP.DiscreteWindGustModel1_Gx
                    section.data(1).logicalSrcIdx = 92;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.DiscreteWindGustModel1_Gy
                    section.data(2).logicalSrcIdx = 93;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.DiscreteWindGustModel1_Gz
                    section.data(3).logicalSrcIdx = 94;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 229;
            section.data(229)  = dumData; %prealloc

                    ;% rtP.x_Y0
                    section.data(1).logicalSrcIdx = 95;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.DistanceintoGustxLimitedtogustlengthd_IC
                    section.data(2).logicalSrcIdx = 96;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.DistanceintoGustxLimitedtogustlengthd_LowerSat
                    section.data(3).logicalSrcIdx = 97;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Gain3_Gain
                    section.data(4).logicalSrcIdx = 98;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.DeadZone2_Start
                    section.data(5).logicalSrcIdx = 99;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.DeadZone2_End
                    section.data(6).logicalSrcIdx = 100;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.Gain2_Gain
                    section.data(7).logicalSrcIdx = 101;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.DeadZone1_Start
                    section.data(8).logicalSrcIdx = 102;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.DeadZone1_End
                    section.data(9).logicalSrcIdx = 103;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.Gain1_Gain
                    section.data(10).logicalSrcIdx = 104;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.Saturation1_UpperSat
                    section.data(11).logicalSrcIdx = 105;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.Saturation1_LowerSat
                    section.data(12).logicalSrcIdx = 106;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.Saturation_UpperSat
                    section.data(13).logicalSrcIdx = 107;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.Saturation_LowerSat
                    section.data(14).logicalSrcIdx = 108;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.DeadZone_Start
                    section.data(15).logicalSrcIdx = 109;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.DeadZone_End
                    section.data(16).logicalSrcIdx = 110;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.Gain_Gain
                    section.data(17).logicalSrcIdx = 111;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.Saturation2_UpperSat
                    section.data(18).logicalSrcIdx = 112;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.Saturation2_LowerSat
                    section.data(19).logicalSrcIdx = 113;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.Saturation3_UpperSat
                    section.data(20).logicalSrcIdx = 114;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.Saturation3_LowerSat
                    section.data(21).logicalSrcIdx = 115;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.Constant4_Value
                    section.data(22).logicalSrcIdx = 116;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.Constant_Value
                    section.data(23).logicalSrcIdx = 117;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.Constant1_Value
                    section.data(24).logicalSrcIdx = 118;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.Constant2_Value
                    section.data(25).logicalSrcIdx = 119;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.SFunction_P1_Size
                    section.data(26).logicalSrcIdx = 120;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.SFunction_P1
                    section.data(27).logicalSrcIdx = 121;
                    section.data(27).dtTransOffset = 27;

                    ;% rtP.Numberofsimstepstoskip_Value
                    section.data(28).logicalSrcIdx = 122;
                    section.data(28).dtTransOffset = 72;

                    ;% rtP.Bias_Bias
                    section.data(29).logicalSrcIdx = 123;
                    section.data(29).dtTransOffset = 73;

                    ;% rtP.Gain_Gain_pu50nbciii
                    section.data(30).logicalSrcIdx = 124;
                    section.data(30).dtTransOffset = 74;

                    ;% rtP.Bias1_Bias
                    section.data(31).logicalSrcIdx = 125;
                    section.data(31).dtTransOffset = 75;

                    ;% rtP.Bias_Bias_jjp2hxzsy1
                    section.data(32).logicalSrcIdx = 126;
                    section.data(32).dtTransOffset = 76;

                    ;% rtP.Bias1_Bias_jgjixhvhbb
                    section.data(33).logicalSrcIdx = 127;
                    section.data(33).dtTransOffset = 77;

                    ;% rtP.Bias_Bias_gvhsf5vuyl
                    section.data(34).logicalSrcIdx = 128;
                    section.data(34).dtTransOffset = 78;

                    ;% rtP.Bias1_Bias_gvvhyuyzsh
                    section.data(35).logicalSrcIdx = 129;
                    section.data(35).dtTransOffset = 79;

                    ;% rtP.Constant_Value_p2sv0iawa4
                    section.data(36).logicalSrcIdx = 130;
                    section.data(36).dtTransOffset = 80;

                    ;% rtP.Constant_Value_ddzso0nzyx
                    section.data(37).logicalSrcIdx = 131;
                    section.data(37).dtTransOffset = 81;

                    ;% rtP.Constant_Value_covdqsa2k4
                    section.data(38).logicalSrcIdx = 132;
                    section.data(38).dtTransOffset = 82;

                    ;% rtP.phithetapsi_WrappedStateUpperValue
                    section.data(39).logicalSrcIdx = 133;
                    section.data(39).dtTransOffset = 83;

                    ;% rtP.phithetapsi_WrappedStateLowerValue
                    section.data(40).logicalSrcIdx = 134;
                    section.data(40).dtTransOffset = 84;

                    ;% rtP.Gain_Gain_mszzowmsuk
                    section.data(41).logicalSrcIdx = 135;
                    section.data(41).dtTransOffset = 85;

                    ;% rtP.uDLookupTable_tableData
                    section.data(42).logicalSrcIdx = 136;
                    section.data(42).dtTransOffset = 86;

                    ;% rtP.uDLookupTable_bp01Data
                    section.data(43).logicalSrcIdx = 137;
                    section.data(43).dtTransOffset = 89;

                    ;% rtP.Gain_Gain_laazcdnihk
                    section.data(44).logicalSrcIdx = 138;
                    section.data(44).dtTransOffset = 92;

                    ;% rtP.Gain_Gain_hkwjozvx2n
                    section.data(45).logicalSrcIdx = 139;
                    section.data(45).dtTransOffset = 93;

                    ;% rtP.Gain_Gain_mw0psof1f3
                    section.data(46).logicalSrcIdx = 140;
                    section.data(46).dtTransOffset = 94;

                    ;% rtP.Memory1_InitialCondition
                    section.data(47).logicalSrcIdx = 141;
                    section.data(47).dtTransOffset = 95;

                    ;% rtP.Switch_Threshold
                    section.data(48).logicalSrcIdx = 142;
                    section.data(48).dtTransOffset = 96;

                    ;% rtP.Switch_Threshold_keldsx1mfj
                    section.data(49).logicalSrcIdx = 143;
                    section.data(49).dtTransOffset = 97;

                    ;% rtP.Gain_Gain_n4k11xn3pg
                    section.data(50).logicalSrcIdx = 144;
                    section.data(50).dtTransOffset = 98;

                    ;% rtP.Gain_Gain_lmgk2iw1td
                    section.data(51).logicalSrcIdx = 145;
                    section.data(51).dtTransOffset = 99;

                    ;% rtP.Gain_Gain_aycx2qnlhg
                    section.data(52).logicalSrcIdx = 146;
                    section.data(52).dtTransOffset = 100;

                    ;% rtP.Gain_Gain_fqf4wrixzl
                    section.data(53).logicalSrcIdx = 147;
                    section.data(53).dtTransOffset = 101;

                    ;% rtP.Memory1_InitialCondition_pjfkz2iyv3
                    section.data(54).logicalSrcIdx = 148;
                    section.data(54).dtTransOffset = 102;

                    ;% rtP.Switch_Threshold_lm0zosgxar
                    section.data(55).logicalSrcIdx = 149;
                    section.data(55).dtTransOffset = 103;

                    ;% rtP.Actuatorprocessingandtransportdelay10ms_InitialCondition
                    section.data(56).logicalSrcIdx = 150;
                    section.data(56).dtTransOffset = 104;

                    ;% rtP.LapseRate_Gain
                    section.data(57).logicalSrcIdx = 151;
                    section.data(57).dtTransOffset = 204;

                    ;% rtP.uT0_Gain
                    section.data(58).logicalSrcIdx = 152;
                    section.data(58).dtTransOffset = 205;

                    ;% rtP.rho0_Gain
                    section.data(59).logicalSrcIdx = 153;
                    section.data(59).dtTransOffset = 206;

                    ;% rtP.LimitaltitudetoStratosphere_UpperSat
                    section.data(60).logicalSrcIdx = 154;
                    section.data(60).dtTransOffset = 207;

                    ;% rtP.LimitaltitudetoStratosphere_LowerSat
                    section.data(61).logicalSrcIdx = 155;
                    section.data(61).dtTransOffset = 208;

                    ;% rtP.gR_Gain
                    section.data(62).logicalSrcIdx = 156;
                    section.data(62).dtTransOffset = 209;

                    ;% rtP.VariableTransportDelay1_MaxDelay
                    section.data(63).logicalSrcIdx = 157;
                    section.data(63).dtTransOffset = 210;

                    ;% rtP.VariableTransportDelay1_InitOutput
                    section.data(64).logicalSrcIdx = 158;
                    section.data(64).dtTransOffset = 211;

                    ;% rtP.Step_Time
                    section.data(65).logicalSrcIdx = 159;
                    section.data(65).dtTransOffset = 212;

                    ;% rtP.Step_Y0
                    section.data(66).logicalSrcIdx = 160;
                    section.data(66).dtTransOffset = 213;

                    ;% rtP.Step_YFinal
                    section.data(67).logicalSrcIdx = 161;
                    section.data(67).dtTransOffset = 214;

                    ;% rtP.Switch_Threshold_barcjzagnb
                    section.data(68).logicalSrcIdx = 162;
                    section.data(68).dtTransOffset = 215;

                    ;% rtP.VariableTransportDelay_MaxDelay
                    section.data(69).logicalSrcIdx = 163;
                    section.data(69).dtTransOffset = 216;

                    ;% rtP.VariableTransportDelay_InitOutput
                    section.data(70).logicalSrcIdx = 164;
                    section.data(70).dtTransOffset = 217;

                    ;% rtP.Step1_Time
                    section.data(71).logicalSrcIdx = 165;
                    section.data(71).dtTransOffset = 218;

                    ;% rtP.Step1_Y0
                    section.data(72).logicalSrcIdx = 166;
                    section.data(72).dtTransOffset = 219;

                    ;% rtP.Step1_YFinal
                    section.data(73).logicalSrcIdx = 167;
                    section.data(73).dtTransOffset = 220;

                    ;% rtP.Switch1_Threshold
                    section.data(74).logicalSrcIdx = 168;
                    section.data(74).dtTransOffset = 221;

                    ;% rtP.Switch_Threshold_fa0qrtsblw
                    section.data(75).logicalSrcIdx = 169;
                    section.data(75).dtTransOffset = 222;

                    ;% rtP.Memory_InitialCondition
                    section.data(76).logicalSrcIdx = 170;
                    section.data(76).dtTransOffset = 223;

                    ;% rtP.Saturation1_UpperSat_faajmjiyue
                    section.data(77).logicalSrcIdx = 171;
                    section.data(77).dtTransOffset = 226;

                    ;% rtP.Saturation1_LowerSat_fjfihtgctt
                    section.data(78).logicalSrcIdx = 172;
                    section.data(78).dtTransOffset = 227;

                    ;% rtP.Saturation_UpperSat_hpioqrnjvm
                    section.data(79).logicalSrcIdx = 173;
                    section.data(79).dtTransOffset = 228;

                    ;% rtP.Saturation_LowerSat_ckp25ja5tp
                    section.data(80).logicalSrcIdx = 174;
                    section.data(80).dtTransOffset = 229;

                    ;% rtP.Switch_Threshold_nwgyj0aeyx
                    section.data(81).logicalSrcIdx = 175;
                    section.data(81).dtTransOffset = 230;

                    ;% rtP.Memory_InitialCondition_hnyjdse4h4
                    section.data(82).logicalSrcIdx = 176;
                    section.data(82).dtTransOffset = 231;

                    ;% rtP.Saturation1_UpperSat_jujzsatqjs
                    section.data(83).logicalSrcIdx = 177;
                    section.data(83).dtTransOffset = 234;

                    ;% rtP.Saturation1_LowerSat_ifds41vj3d
                    section.data(84).logicalSrcIdx = 178;
                    section.data(84).dtTransOffset = 235;

                    ;% rtP.Saturation_UpperSat_n2gmlqdobk
                    section.data(85).logicalSrcIdx = 179;
                    section.data(85).dtTransOffset = 236;

                    ;% rtP.Saturation_LowerSat_egflfzvuqx
                    section.data(86).logicalSrcIdx = 180;
                    section.data(86).dtTransOffset = 237;

                    ;% rtP.FrictionCoefficient_Gain
                    section.data(87).logicalSrcIdx = 181;
                    section.data(87).dtTransOffset = 238;

                    ;% rtP.FrictionCoefficient_Gain_bld3rumxab
                    section.data(88).logicalSrcIdx = 182;
                    section.data(88).dtTransOffset = 239;

                    ;% rtP.Switch_Threshold_kslqyxqwsc
                    section.data(89).logicalSrcIdx = 183;
                    section.data(89).dtTransOffset = 240;

                    ;% rtP.Memory_InitialCondition_iqeioiam5g
                    section.data(90).logicalSrcIdx = 184;
                    section.data(90).dtTransOffset = 241;

                    ;% rtP.Saturation1_UpperSat_bgrqxpsgy2
                    section.data(91).logicalSrcIdx = 185;
                    section.data(91).dtTransOffset = 244;

                    ;% rtP.Saturation1_LowerSat_mtmmhddwjb
                    section.data(92).logicalSrcIdx = 186;
                    section.data(92).dtTransOffset = 245;

                    ;% rtP.Saturation_UpperSat_fkspttvlxs
                    section.data(93).logicalSrcIdx = 187;
                    section.data(93).dtTransOffset = 246;

                    ;% rtP.Saturation_LowerSat_ihlfa0mqdb
                    section.data(94).logicalSrcIdx = 188;
                    section.data(94).dtTransOffset = 247;

                    ;% rtP.FrictionCoefficient_Gain_jiuksux40s
                    section.data(95).logicalSrcIdx = 189;
                    section.data(95).dtTransOffset = 248;

                    ;% rtP.Gain_Gain_cssolhvy5w
                    section.data(96).logicalSrcIdx = 190;
                    section.data(96).dtTransOffset = 249;

                    ;% rtP.Gain_Gain_ay20xvgxq5
                    section.data(97).logicalSrcIdx = 191;
                    section.data(97).dtTransOffset = 250;

                    ;% rtP.Gain_Gain_iuh3lzw4i0
                    section.data(98).logicalSrcIdx = 192;
                    section.data(98).dtTransOffset = 251;

                    ;% rtP.Gain_Gain_inh0c1mtep
                    section.data(99).logicalSrcIdx = 193;
                    section.data(99).dtTransOffset = 252;

                    ;% rtP.Gain_Gain_iso0wdlaw3
                    section.data(100).logicalSrcIdx = 194;
                    section.data(100).dtTransOffset = 253;

                    ;% rtP.Gain_Gain_otfwfmpf50
                    section.data(101).logicalSrcIdx = 195;
                    section.data(101).dtTransOffset = 254;

                    ;% rtP.Gain_Gain_n2lq1m5z15
                    section.data(102).logicalSrcIdx = 196;
                    section.data(102).dtTransOffset = 255;

                    ;% rtP.P0_Gain
                    section.data(103).logicalSrcIdx = 197;
                    section.data(103).dtTransOffset = 256;

                    ;% rtP.FCCframedelay10msassumed100HzFCC_InitialCondition
                    section.data(104).logicalSrcIdx = 198;
                    section.data(104).dtTransOffset = 257;

                    ;% rtP.Gain1_Gain_h4hra1gikq
                    section.data(105).logicalSrcIdx = 199;
                    section.data(105).dtTransOffset = 357;

                    ;% rtP.Gain2_Gain_ic5npr3xa1
                    section.data(106).logicalSrcIdx = 200;
                    section.data(106).dtTransOffset = 358;

                    ;% rtP.Gain_Gain_g41sdlhqvv
                    section.data(107).logicalSrcIdx = 201;
                    section.data(107).dtTransOffset = 359;

                    ;% rtP.uDLookupTable1_tableData
                    section.data(108).logicalSrcIdx = 202;
                    section.data(108).dtTransOffset = 360;

                    ;% rtP.uDLookupTable1_bp01Data
                    section.data(109).logicalSrcIdx = 203;
                    section.data(109).dtTransOffset = 362;

                    ;% rtP.Gain_Gain_b0rnnooty0
                    section.data(110).logicalSrcIdx = 204;
                    section.data(110).dtTransOffset = 364;

                    ;% rtP.Gain_Gain_lercwvznpd
                    section.data(111).logicalSrcIdx = 205;
                    section.data(111).dtTransOffset = 365;

                    ;% rtP.Delay1_InitialCondition
                    section.data(112).logicalSrcIdx = 206;
                    section.data(112).dtTransOffset = 366;

                    ;% rtP.Delay10_InitialCondition
                    section.data(113).logicalSrcIdx = 207;
                    section.data(113).dtTransOffset = 367;

                    ;% rtP.Delay18_InitialCondition
                    section.data(114).logicalSrcIdx = 208;
                    section.data(114).dtTransOffset = 368;

                    ;% rtP.Delay19_InitialCondition
                    section.data(115).logicalSrcIdx = 209;
                    section.data(115).dtTransOffset = 383;

                    ;% rtP.Delay2_InitialCondition
                    section.data(116).logicalSrcIdx = 210;
                    section.data(116).dtTransOffset = 384;

                    ;% rtP.Delay20_InitialCondition
                    section.data(117).logicalSrcIdx = 211;
                    section.data(117).dtTransOffset = 385;

                    ;% rtP.Delay21_InitialCondition
                    section.data(118).logicalSrcIdx = 212;
                    section.data(118).dtTransOffset = 386;

                    ;% rtP.Delay22_InitialCondition
                    section.data(119).logicalSrcIdx = 213;
                    section.data(119).dtTransOffset = 401;

                    ;% rtP.Delay23_InitialCondition
                    section.data(120).logicalSrcIdx = 214;
                    section.data(120).dtTransOffset = 402;

                    ;% rtP.Delay25_InitialCondition
                    section.data(121).logicalSrcIdx = 215;
                    section.data(121).dtTransOffset = 403;

                    ;% rtP.Delay26_InitialCondition
                    section.data(122).logicalSrcIdx = 216;
                    section.data(122).dtTransOffset = 404;

                    ;% rtP.Delay27_InitialCondition
                    section.data(123).logicalSrcIdx = 217;
                    section.data(123).dtTransOffset = 405;

                    ;% rtP.Delay28_InitialCondition
                    section.data(124).logicalSrcIdx = 218;
                    section.data(124).dtTransOffset = 406;

                    ;% rtP.Delay29_InitialCondition
                    section.data(125).logicalSrcIdx = 219;
                    section.data(125).dtTransOffset = 407;

                    ;% rtP.Delay3_InitialCondition
                    section.data(126).logicalSrcIdx = 220;
                    section.data(126).dtTransOffset = 408;

                    ;% rtP.Delay35_InitialCondition
                    section.data(127).logicalSrcIdx = 221;
                    section.data(127).dtTransOffset = 409;

                    ;% rtP.Delay6_InitialCondition
                    section.data(128).logicalSrcIdx = 222;
                    section.data(128).dtTransOffset = 410;

                    ;% rtP.Delay7_InitialCondition
                    section.data(129).logicalSrcIdx = 223;
                    section.data(129).dtTransOffset = 411;

                    ;% rtP.Delay8_InitialCondition
                    section.data(130).logicalSrcIdx = 224;
                    section.data(130).dtTransOffset = 412;

                    ;% rtP.Delay9_InitialCondition
                    section.data(131).logicalSrcIdx = 225;
                    section.data(131).dtTransOffset = 413;

                    ;% rtP._InitialCondition
                    section.data(132).logicalSrcIdx = 226;
                    section.data(132).dtTransOffset = 414;

                    ;% rtP.sms_Gain
                    section.data(133).logicalSrcIdx = 227;
                    section.data(133).dtTransOffset = 415;

                    ;% rtP.SFunction_P1_Size_msgrnckvzs
                    section.data(134).logicalSrcIdx = 228;
                    section.data(134).dtTransOffset = 416;

                    ;% rtP.SFunction_P1_gkb1uhxswe
                    section.data(135).logicalSrcIdx = 229;
                    section.data(135).dtTransOffset = 418;

                    ;% rtP.Constant_Value_grffgcb3uj
                    section.data(136).logicalSrcIdx = 230;
                    section.data(136).dtTransOffset = 419;

                    ;% rtP.Constant1_Value_ep5qwhnxw4
                    section.data(137).logicalSrcIdx = 231;
                    section.data(137).dtTransOffset = 420;

                    ;% rtP.Constant2_Value_dnaxpvvz45
                    section.data(138).logicalSrcIdx = 232;
                    section.data(138).dtTransOffset = 421;

                    ;% rtP.Constant2_Value_euehonucuw
                    section.data(139).logicalSrcIdx = 233;
                    section.data(139).dtTransOffset = 422;

                    ;% rtP.Constant_Value_o5fhcpqqyu
                    section.data(140).logicalSrcIdx = 234;
                    section.data(140).dtTransOffset = 423;

                    ;% rtP.Constant1_Value_a0rz4phgln
                    section.data(141).logicalSrcIdx = 235;
                    section.data(141).dtTransOffset = 424;

                    ;% rtP.Bias_Bias_ftrguhqylg
                    section.data(142).logicalSrcIdx = 236;
                    section.data(142).dtTransOffset = 425;

                    ;% rtP.Constant2_Value_mxdetvroc4
                    section.data(143).logicalSrcIdx = 237;
                    section.data(143).dtTransOffset = 426;

                    ;% rtP.Bias1_Bias_kwaqdylxmf
                    section.data(144).logicalSrcIdx = 238;
                    section.data(144).dtTransOffset = 427;

                    ;% rtP.Bias_Bias_konxswsfpe
                    section.data(145).logicalSrcIdx = 239;
                    section.data(145).dtTransOffset = 428;

                    ;% rtP.Gain_Gain_jwbuilkyxy
                    section.data(146).logicalSrcIdx = 240;
                    section.data(146).dtTransOffset = 429;

                    ;% rtP.Bias1_Bias_gdznygtef3
                    section.data(147).logicalSrcIdx = 241;
                    section.data(147).dtTransOffset = 430;

                    ;% rtP.Bias_Bias_kd45ia31j2
                    section.data(148).logicalSrcIdx = 242;
                    section.data(148).dtTransOffset = 431;

                    ;% rtP.Constant2_Value_d2ebp0gj1g
                    section.data(149).logicalSrcIdx = 243;
                    section.data(149).dtTransOffset = 432;

                    ;% rtP.Bias1_Bias_pcofu2atfo
                    section.data(150).logicalSrcIdx = 244;
                    section.data(150).dtTransOffset = 433;

                    ;% rtP.Constant_Value_cds1oetfvb
                    section.data(151).logicalSrcIdx = 245;
                    section.data(151).dtTransOffset = 434;

                    ;% rtP.Constant1_Value_auykfi4siv
                    section.data(152).logicalSrcIdx = 246;
                    section.data(152).dtTransOffset = 435;

                    ;% rtP.Constant2_Value_dc1ztqo1sh
                    section.data(153).logicalSrcIdx = 247;
                    section.data(153).dtTransOffset = 436;

                    ;% rtP.Constant3_Value
                    section.data(154).logicalSrcIdx = 248;
                    section.data(154).dtTransOffset = 437;

                    ;% rtP.Constant_Value_bwixaan2i5
                    section.data(155).logicalSrcIdx = 249;
                    section.data(155).dtTransOffset = 438;

                    ;% rtP.Constant_Value_joj4ebuyjq
                    section.data(156).logicalSrcIdx = 250;
                    section.data(156).dtTransOffset = 439;

                    ;% rtP.Constant_Value_nam4eq1guw
                    section.data(157).logicalSrcIdx = 251;
                    section.data(157).dtTransOffset = 440;

                    ;% rtP.f_Value
                    section.data(158).logicalSrcIdx = 252;
                    section.data(158).dtTransOffset = 441;

                    ;% rtP.Constant2_Value_fqbq1clpin
                    section.data(159).logicalSrcIdx = 253;
                    section.data(159).dtTransOffset = 442;

                    ;% rtP.Constant3_Value_nbcxsvbsnn
                    section.data(160).logicalSrcIdx = 254;
                    section.data(160).dtTransOffset = 443;

                    ;% rtP.Constant2_Value_evxyvbxyx4
                    section.data(161).logicalSrcIdx = 255;
                    section.data(161).dtTransOffset = 444;

                    ;% rtP.Constant3_Value_arqhpk5tsi
                    section.data(162).logicalSrcIdx = 256;
                    section.data(162).dtTransOffset = 445;

                    ;% rtP.Constant2_Value_imckxbitho
                    section.data(163).logicalSrcIdx = 257;
                    section.data(163).dtTransOffset = 446;

                    ;% rtP.Constant3_Value_kdceg0pib4
                    section.data(164).logicalSrcIdx = 258;
                    section.data(164).dtTransOffset = 447;

                    ;% rtP.Constant_Value_lkyy414dse
                    section.data(165).logicalSrcIdx = 259;
                    section.data(165).dtTransOffset = 448;

                    ;% rtP.Constant1_Value_poq4unoobj
                    section.data(166).logicalSrcIdx = 260;
                    section.data(166).dtTransOffset = 449;

                    ;% rtP.Constant_Value_jra04za24u
                    section.data(167).logicalSrcIdx = 261;
                    section.data(167).dtTransOffset = 450;

                    ;% rtP.Constant_Value_lx5fpqludr
                    section.data(168).logicalSrcIdx = 262;
                    section.data(168).dtTransOffset = 453;

                    ;% rtP.Constant_Value_mn4jvly12r
                    section.data(169).logicalSrcIdx = 263;
                    section.data(169).dtTransOffset = 454;

                    ;% rtP.Constant1_Value_dqqxjknpbv
                    section.data(170).logicalSrcIdx = 264;
                    section.data(170).dtTransOffset = 462;

                    ;% rtP.Constant8_Value
                    section.data(171).logicalSrcIdx = 265;
                    section.data(171).dtTransOffset = 470;

                    ;% rtP.Constant_Value_asshyiafnn
                    section.data(172).logicalSrcIdx = 266;
                    section.data(172).dtTransOffset = 486;

                    ;% rtP.Constant1_Value_h01num5fy3
                    section.data(173).logicalSrcIdx = 267;
                    section.data(173).dtTransOffset = 494;

                    ;% rtP.Constant8_Value_gsd4tzxrvv
                    section.data(174).logicalSrcIdx = 268;
                    section.data(174).dtTransOffset = 502;

                    ;% rtP.Constant_Value_b3o3asdnd0
                    section.data(175).logicalSrcIdx = 269;
                    section.data(175).dtTransOffset = 518;

                    ;% rtP.Constant8_Value_fdguqum2g1
                    section.data(176).logicalSrcIdx = 270;
                    section.data(176).dtTransOffset = 539;

                    ;% rtP.Constant8_Value_dn0swibioj
                    section.data(177).logicalSrcIdx = 271;
                    section.data(177).dtTransOffset = 544;

                    ;% rtP.Constant_Value_benf1an55k
                    section.data(178).logicalSrcIdx = 272;
                    section.data(178).dtTransOffset = 546;

                    ;% rtP.Constant8_Value_o2vddtqbhz
                    section.data(179).logicalSrcIdx = 273;
                    section.data(179).dtTransOffset = 567;

                    ;% rtP.Constant8_Value_oaybf0pjve
                    section.data(180).logicalSrcIdx = 274;
                    section.data(180).dtTransOffset = 572;

                    ;% rtP.Constant_Value_ootamvdz1c
                    section.data(181).logicalSrcIdx = 275;
                    section.data(181).dtTransOffset = 574;

                    ;% rtP.Constant1_Value_aexthjzkeg
                    section.data(182).logicalSrcIdx = 276;
                    section.data(182).dtTransOffset = 575;

                    ;% rtP.Constant2_Value_btnragtfjb
                    section.data(183).logicalSrcIdx = 277;
                    section.data(183).dtTransOffset = 576;

                    ;% rtP.AltitudeofTroposphere_Value
                    section.data(184).logicalSrcIdx = 278;
                    section.data(184).dtTransOffset = 585;

                    ;% rtP.Constant_Value_mmbn22yeyo
                    section.data(185).logicalSrcIdx = 279;
                    section.data(185).dtTransOffset = 586;

                    ;% rtP.SeaLevelTemperature_Value
                    section.data(186).logicalSrcIdx = 280;
                    section.data(186).dtTransOffset = 587;

                    ;% rtP.u_Value
                    section.data(187).logicalSrcIdx = 281;
                    section.data(187).dtTransOffset = 588;

                    ;% rtP.Constant_Value_nidy3scify
                    section.data(188).logicalSrcIdx = 282;
                    section.data(188).dtTransOffset = 589;

                    ;% rtP.Gain_Gain_hvvnixqugo
                    section.data(189).logicalSrcIdx = 283;
                    section.data(189).dtTransOffset = 592;

                    ;% rtP.Constant2_Value_eyx5hzotxm
                    section.data(190).logicalSrcIdx = 284;
                    section.data(190).dtTransOffset = 604;

                    ;% rtP.Inclination_Value
                    section.data(191).logicalSrcIdx = 285;
                    section.data(191).dtTransOffset = 616;

                    ;% rtP.Constant_Value_jkrncbjqj3
                    section.data(192).logicalSrcIdx = 286;
                    section.data(192).dtTransOffset = 617;

                    ;% rtP.Multiply_Gain
                    section.data(193).logicalSrcIdx = 287;
                    section.data(193).dtTransOffset = 618;

                    ;% rtP.Constant_Value_jax04gsciy
                    section.data(194).logicalSrcIdx = 288;
                    section.data(194).dtTransOffset = 619;

                    ;% rtP.Constant_Value_ofr0qgx5yn
                    section.data(195).logicalSrcIdx = 289;
                    section.data(195).dtTransOffset = 620;

                    ;% rtP.Constant1_Value_i0jzjc51w0
                    section.data(196).logicalSrcIdx = 290;
                    section.data(196).dtTransOffset = 623;

                    ;% rtP.Constant2_Value_dksr45kxji
                    section.data(197).logicalSrcIdx = 291;
                    section.data(197).dtTransOffset = 626;

                    ;% rtP.Constant_Value_czh5rbe04d
                    section.data(198).logicalSrcIdx = 292;
                    section.data(198).dtTransOffset = 629;

                    ;% rtP.Constant_Value_fgevrsqc4v
                    section.data(199).logicalSrcIdx = 293;
                    section.data(199).dtTransOffset = 630;

                    ;% rtP.Constant1_Value_dgi3p5u40k
                    section.data(200).logicalSrcIdx = 294;
                    section.data(200).dtTransOffset = 631;

                    ;% rtP.Constant2_Value_p2rjztbk2r
                    section.data(201).logicalSrcIdx = 295;
                    section.data(201).dtTransOffset = 632;

                    ;% rtP.Constant_Value_o1yp2gl00i
                    section.data(202).logicalSrcIdx = 296;
                    section.data(202).dtTransOffset = 633;

                    ;% rtP.Constant1_Value_eyubj2pyfz
                    section.data(203).logicalSrcIdx = 297;
                    section.data(203).dtTransOffset = 634;

                    ;% rtP.Constant_Value_dkfqzg3jt5
                    section.data(204).logicalSrcIdx = 298;
                    section.data(204).dtTransOffset = 635;

                    ;% rtP.Constant_Value_gptvvpedc0
                    section.data(205).logicalSrcIdx = 299;
                    section.data(205).dtTransOffset = 636;

                    ;% rtP.Constant1_Value_es2hmwpsih
                    section.data(206).logicalSrcIdx = 300;
                    section.data(206).dtTransOffset = 637;

                    ;% rtP.Constant2_Value_er0w5mtd4j
                    section.data(207).logicalSrcIdx = 301;
                    section.data(207).dtTransOffset = 638;

                    ;% rtP.Constant_Value_aqtgynqvul
                    section.data(208).logicalSrcIdx = 302;
                    section.data(208).dtTransOffset = 639;

                    ;% rtP.Constant1_Value_jtm4r5yj4j
                    section.data(209).logicalSrcIdx = 303;
                    section.data(209).dtTransOffset = 640;

                    ;% rtP.Constant_Value_dosqprdn32
                    section.data(210).logicalSrcIdx = 304;
                    section.data(210).dtTransOffset = 641;

                    ;% rtP.Constant_Value_ivz01hdudw
                    section.data(211).logicalSrcIdx = 305;
                    section.data(211).dtTransOffset = 642;

                    ;% rtP.Constant1_Value_nw1qma1fjc
                    section.data(212).logicalSrcIdx = 306;
                    section.data(212).dtTransOffset = 643;

                    ;% rtP.Constant2_Value_hhw30thswa
                    section.data(213).logicalSrcIdx = 307;
                    section.data(213).dtTransOffset = 644;

                    ;% rtP.Constant_Value_feb2wg5gid
                    section.data(214).logicalSrcIdx = 308;
                    section.data(214).dtTransOffset = 645;

                    ;% rtP.Constant1_Value_f4dk2n3412
                    section.data(215).logicalSrcIdx = 309;
                    section.data(215).dtTransOffset = 646;

                    ;% rtP.Constant1_Value_grmbs0ngpp
                    section.data(216).logicalSrcIdx = 310;
                    section.data(216).dtTransOffset = 647;

                    ;% rtP.Constant2_Value_eyfztz0fxi
                    section.data(217).logicalSrcIdx = 311;
                    section.data(217).dtTransOffset = 650;

                    ;% rtP.Constant2_Value_p0sma1ifq3
                    section.data(218).logicalSrcIdx = 312;
                    section.data(218).dtTransOffset = 653;

                    ;% rtP.Constant1_Value_aeivuiuwhs
                    section.data(219).logicalSrcIdx = 313;
                    section.data(219).dtTransOffset = 654;

                    ;% rtP.Constant1_Value_crvf1ymqjc
                    section.data(220).logicalSrcIdx = 314;
                    section.data(220).dtTransOffset = 655;

                    ;% rtP.Constant_Value_ph3kv45jlz
                    section.data(221).logicalSrcIdx = 315;
                    section.data(221).dtTransOffset = 656;

                    ;% rtP.Constant3_Value_gdofiqtr3v
                    section.data(222).logicalSrcIdx = 316;
                    section.data(222).dtTransOffset = 657;

                    ;% rtP.Constant1_Value_po2h1uw5ro
                    section.data(223).logicalSrcIdx = 317;
                    section.data(223).dtTransOffset = 658;

                    ;% rtP.Constant_Value_nxyjglhqnl
                    section.data(224).logicalSrcIdx = 318;
                    section.data(224).dtTransOffset = 659;

                    ;% rtP.deviceID_Value
                    section.data(225).logicalSrcIdx = 319;
                    section.data(225).dtTransOffset = 660;

                    ;% rtP.Constant1_Value_ksii3tuk3x
                    section.data(226).logicalSrcIdx = 320;
                    section.data(226).dtTransOffset = 661;

                    ;% rtP.Constant2_Value_ovsjzrpt3j
                    section.data(227).logicalSrcIdx = 321;
                    section.data(227).dtTransOffset = 662;

                    ;% rtP.Constant_Value_b3waei3ut2
                    section.data(228).logicalSrcIdx = 322;
                    section.data(228).dtTransOffset = 663;

                    ;% rtP.const_Value
                    section.data(229).logicalSrcIdx = 323;
                    section.data(229).dtTransOffset = 664;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 22;
            section.data(22)  = dumData; %prealloc

                    ;% rtP.Limitaltitudetotroposhere_UpperSat
                    section.data(1).logicalSrcIdx = 324;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Limitaltitudetotroposhere_LowerSat
                    section.data(2).logicalSrcIdx = 325;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Gain_Gain_igdiaogfc0
                    section.data(3).logicalSrcIdx = 326;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Gain_Gain_acyum2oy5l
                    section.data(4).logicalSrcIdx = 327;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.uDLookupTable_bp01Data_anwusoh2uk
                    section.data(5).logicalSrcIdx = 328;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.uDLookupTable1_bp01Data_lct4mwibxn
                    section.data(6).logicalSrcIdx = 329;
                    section.data(6).dtTransOffset = 10;

                    ;% rtP.uDLookupTable2_bp01Data
                    section.data(7).logicalSrcIdx = 330;
                    section.data(7).dtTransOffset = 16;

                    ;% rtP.Saturation_UpperSat_b2a52laupk
                    section.data(8).logicalSrcIdx = 331;
                    section.data(8).dtTransOffset = 22;

                    ;% rtP.Saturation_LowerSat_gotqetz1tq
                    section.data(9).logicalSrcIdx = 332;
                    section.data(9).dtTransOffset = 23;

                    ;% rtP.Gain2_Gain_pp1pwsqq1n
                    section.data(10).logicalSrcIdx = 333;
                    section.data(10).dtTransOffset = 24;

                    ;% rtP.Gain3_Gain_i1yimbgde1
                    section.data(11).logicalSrcIdx = 334;
                    section.data(11).dtTransOffset = 25;

                    ;% rtP.Prelookup_BreakpointsData
                    section.data(12).logicalSrcIdx = 335;
                    section.data(12).dtTransOffset = 26;

                    ;% rtP.Prelookup1_BreakpointsData
                    section.data(13).logicalSrcIdx = 336;
                    section.data(13).dtTransOffset = 39;

                    ;% rtP.Gain_Gain_llsqu3hkdm
                    section.data(14).logicalSrcIdx = 337;
                    section.data(14).dtTransOffset = 54;

                    ;% rtP.Constant_Value_guxqtm0enf
                    section.data(15).logicalSrcIdx = 338;
                    section.data(15).dtTransOffset = 55;

                    ;% rtP.Constant7_Value
                    section.data(16).logicalSrcIdx = 339;
                    section.data(16).dtTransOffset = 56;

                    ;% rtP.Constant1_Value_lhco2hmkqd
                    section.data(17).logicalSrcIdx = 340;
                    section.data(17).dtTransOffset = 72;

                    ;% rtP.NodePoints_Value
                    section.data(18).logicalSrcIdx = 341;
                    section.data(18).dtTransOffset = 120;

                    ;% rtP.NodePoints_Value_d4b2lmxebb
                    section.data(19).logicalSrcIdx = 342;
                    section.data(19).dtTransOffset = 141;

                    ;% rtP.Constant1_Value_b4mc4ixfm2
                    section.data(20).logicalSrcIdx = 343;
                    section.data(20).dtTransOffset = 162;

                    ;% rtP.extra_drag_Value
                    section.data(21).logicalSrcIdx = 344;
                    section.data(21).dtTransOffset = 163;

                    ;% rtP.gear_drag_Value
                    section.data(22).logicalSrcIdx = 345;
                    section.data(22).dtTransOffset = 164;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section

            section.nData     = 57;
            section.data(57)  = dumData; %prealloc

                    ;% rtP.InterpolationUsingPrelookup1_dimSize
                    section.data(1).logicalSrcIdx = 346;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex
                    section.data(2).logicalSrcIdx = 347;
                    section.data(2).dtTransOffset = 4;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_gfiklomvd1
                    section.data(3).logicalSrcIdx = 348;
                    section.data(3).dtTransOffset = 8;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex_kpkpckmswm
                    section.data(4).logicalSrcIdx = 349;
                    section.data(4).dtTransOffset = 12;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize
                    section.data(5).logicalSrcIdx = 350;
                    section.data(5).dtTransOffset = 16;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex
                    section.data(6).logicalSrcIdx = 351;
                    section.data(6).dtTransOffset = 20;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_nrl20k3nz5
                    section.data(7).logicalSrcIdx = 352;
                    section.data(7).dtTransOffset = 24;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex_halnsma1cb
                    section.data(8).logicalSrcIdx = 353;
                    section.data(8).dtTransOffset = 28;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize
                    section.data(9).logicalSrcIdx = 354;
                    section.data(9).dtTransOffset = 32;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex
                    section.data(10).logicalSrcIdx = 355;
                    section.data(10).dtTransOffset = 36;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_bwdov31odu
                    section.data(11).logicalSrcIdx = 356;
                    section.data(11).dtTransOffset = 40;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex_dnuuotdmkt
                    section.data(12).logicalSrcIdx = 357;
                    section.data(12).dtTransOffset = 44;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize
                    section.data(13).logicalSrcIdx = 358;
                    section.data(13).dtTransOffset = 48;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex
                    section.data(14).logicalSrcIdx = 359;
                    section.data(14).dtTransOffset = 52;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_lcwylc1smw
                    section.data(15).logicalSrcIdx = 360;
                    section.data(15).dtTransOffset = 56;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex_cy2xlkh5vq
                    section.data(16).logicalSrcIdx = 361;
                    section.data(16).dtTransOffset = 60;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize
                    section.data(17).logicalSrcIdx = 362;
                    section.data(17).dtTransOffset = 64;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex
                    section.data(18).logicalSrcIdx = 363;
                    section.data(18).dtTransOffset = 68;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_c5irdqqd1s
                    section.data(19).logicalSrcIdx = 364;
                    section.data(19).dtTransOffset = 72;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex_d44fsejhpt
                    section.data(20).logicalSrcIdx = 365;
                    section.data(20).dtTransOffset = 76;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize
                    section.data(21).logicalSrcIdx = 366;
                    section.data(21).dtTransOffset = 80;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex
                    section.data(22).logicalSrcIdx = 367;
                    section.data(22).dtTransOffset = 84;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_iia0rqhr03
                    section.data(23).logicalSrcIdx = 368;
                    section.data(23).dtTransOffset = 88;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex_f1aiexynmu
                    section.data(24).logicalSrcIdx = 369;
                    section.data(24).dtTransOffset = 92;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_cc1prjb2oo
                    section.data(25).logicalSrcIdx = 370;
                    section.data(25).dtTransOffset = 96;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex_n2qqbs4dob
                    section.data(26).logicalSrcIdx = 371;
                    section.data(26).dtTransOffset = 100;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_kx41jhq53z
                    section.data(27).logicalSrcIdx = 372;
                    section.data(27).dtTransOffset = 104;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex_dvymep4nij
                    section.data(28).logicalSrcIdx = 373;
                    section.data(28).dtTransOffset = 108;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_j2ofnaf0w0
                    section.data(29).logicalSrcIdx = 374;
                    section.data(29).dtTransOffset = 112;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex_fiuiapwlsq
                    section.data(30).logicalSrcIdx = 375;
                    section.data(30).dtTransOffset = 116;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_duz043yjyq
                    section.data(31).logicalSrcIdx = 376;
                    section.data(31).dtTransOffset = 120;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex_bi1sjla3q2
                    section.data(32).logicalSrcIdx = 377;
                    section.data(32).dtTransOffset = 124;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_n5hof3ggty
                    section.data(33).logicalSrcIdx = 378;
                    section.data(33).dtTransOffset = 128;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex_frabtm3htz
                    section.data(34).logicalSrcIdx = 379;
                    section.data(34).dtTransOffset = 132;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_dkrtirzueo
                    section.data(35).logicalSrcIdx = 380;
                    section.data(35).dtTransOffset = 136;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex_imdp4seazn
                    section.data(36).logicalSrcIdx = 381;
                    section.data(36).dtTransOffset = 140;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_dqlnhgz1zi
                    section.data(37).logicalSrcIdx = 382;
                    section.data(37).dtTransOffset = 144;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex_o4wzqxphno
                    section.data(38).logicalSrcIdx = 383;
                    section.data(38).dtTransOffset = 148;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_p4aarrlaxb
                    section.data(39).logicalSrcIdx = 384;
                    section.data(39).dtTransOffset = 152;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex_mqwubj3l1q
                    section.data(40).logicalSrcIdx = 385;
                    section.data(40).dtTransOffset = 156;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_hlna0n1104
                    section.data(41).logicalSrcIdx = 386;
                    section.data(41).dtTransOffset = 160;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex_p1qlpsazb4
                    section.data(42).logicalSrcIdx = 387;
                    section.data(42).dtTransOffset = 164;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_p4p42jneab
                    section.data(43).logicalSrcIdx = 388;
                    section.data(43).dtTransOffset = 168;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex_oxrypmydry
                    section.data(44).logicalSrcIdx = 389;
                    section.data(44).dtTransOffset = 172;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_cdsngd0wzd
                    section.data(45).logicalSrcIdx = 390;
                    section.data(45).dtTransOffset = 176;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex_g3wkr4rrcb
                    section.data(46).logicalSrcIdx = 391;
                    section.data(46).dtTransOffset = 180;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_dpanpvfjmk
                    section.data(47).logicalSrcIdx = 392;
                    section.data(47).dtTransOffset = 184;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex_mdnu5qffrq
                    section.data(48).logicalSrcIdx = 393;
                    section.data(48).dtTransOffset = 188;

                    ;% rtP.V_induced_dimSize
                    section.data(49).logicalSrcIdx = 394;
                    section.data(49).dtTransOffset = 192;

                    ;% rtP.alpha_induced_dimSize
                    section.data(50).logicalSrcIdx = 395;
                    section.data(50).dtTransOffset = 196;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_ff4dr0zil3
                    section.data(51).logicalSrcIdx = 396;
                    section.data(51).dtTransOffset = 200;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_kfgynmyj32
                    section.data(52).logicalSrcIdx = 397;
                    section.data(52).dtTransOffset = 203;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_m2ki2jhx1z
                    section.data(53).logicalSrcIdx = 398;
                    section.data(53).dtTransOffset = 206;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_juyddnk1fb
                    section.data(54).logicalSrcIdx = 399;
                    section.data(54).dtTransOffset = 209;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_mnvowrob4d
                    section.data(55).logicalSrcIdx = 400;
                    section.data(55).dtTransOffset = 212;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_lpul1da2p2
                    section.data(56).logicalSrcIdx = 401;
                    section.data(56).dtTransOffset = 215;

                    ;% rtP.Plookup_maxIndex
                    section.data(57).logicalSrcIdx = 402;
                    section.data(57).dtTransOffset = 218;

            nTotData = nTotData + section.nData;
            paramMap.sections(15) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtP.Constant_Value_l3yr2jaxah
                    section.data(1).logicalSrcIdx = 403;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant1_Value_dhktifwxn5
                    section.data(2).logicalSrcIdx = 404;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Constant_Value_hagifheq3t
                    section.data(3).logicalSrcIdx = 405;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.Constant1_Value_apy2wpsmee
                    section.data(4).logicalSrcIdx = 406;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.Constant_Value_bmpfzxx1ux
                    section.data(5).logicalSrcIdx = 407;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.Constant1_Value_fad3jx5usw
                    section.data(6).logicalSrcIdx = 408;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(16) = section;
            clear section

            section.nData     = 17;
            section.data(17)  = dumData; %prealloc

                    ;% rtP.Constant_Value_ecr3ukwupu
                    section.data(1).logicalSrcIdx = 409;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Constant_Value_cj4suguqdh
                    section.data(2).logicalSrcIdx = 410;
                    section.data(2).dtTransOffset = 45;

                    ;% rtP.ManualSwitch_CurrentSetting
                    section.data(3).logicalSrcIdx = 411;
                    section.data(3).dtTransOffset = 93;

                    ;% rtP.ManualSwitch1_CurrentSetting
                    section.data(4).logicalSrcIdx = 412;
                    section.data(4).dtTransOffset = 94;

                    ;% rtP.ManualSwitch1_CurrentSetting_cwepdspi5f
                    section.data(5).logicalSrcIdx = 413;
                    section.data(5).dtTransOffset = 95;

                    ;% rtP.Constant_Value_ezp4vos5at
                    section.data(6).logicalSrcIdx = 414;
                    section.data(6).dtTransOffset = 96;

                    ;% rtP.Constant_Value_o1jhv21mne
                    section.data(7).logicalSrcIdx = 415;
                    section.data(7).dtTransOffset = 135;

                    ;% rtP.Constant_Value_oln3j4ocph
                    section.data(8).logicalSrcIdx = 416;
                    section.data(8).dtTransOffset = 174;

                    ;% rtP.Constant_Value_deiptb1fdi
                    section.data(9).logicalSrcIdx = 417;
                    section.data(9).dtTransOffset = 203;

                    ;% rtP.Constant_Value_bunajjeyd1
                    section.data(10).logicalSrcIdx = 418;
                    section.data(10).dtTransOffset = 230;

                    ;% rtP.Constant_Value_fu24dwcohf
                    section.data(11).logicalSrcIdx = 419;
                    section.data(11).dtTransOffset = 270;

                    ;% rtP.Constant_Value_p45zmbuefy
                    section.data(12).logicalSrcIdx = 420;
                    section.data(12).dtTransOffset = 310;

                    ;% rtP.Constant_Value_mpqd4zb22a
                    section.data(13).logicalSrcIdx = 421;
                    section.data(13).dtTransOffset = 342;

                    ;% rtP.Constant_Value_prr5w4kjl2
                    section.data(14).logicalSrcIdx = 422;
                    section.data(14).dtTransOffset = 379;

                    ;% rtP.Constant_Value_lqvyli4q5s
                    section.data(15).logicalSrcIdx = 423;
                    section.data(15).dtTransOffset = 416;

                    ;% rtP.Constant_Value_e2xroppgrn
                    section.data(16).logicalSrcIdx = 424;
                    section.data(16).dtTransOffset = 453;

                    ;% rtP.Constant_Value_nmj1ootknt
                    section.data(17).logicalSrcIdx = 425;
                    section.data(17).dtTransOffset = 504;

            nTotData = nTotData + section.nData;
            paramMap.sections(17) = section;
            clear section

            section.nData     = 32;
            section.data(32)  = dumData; %prealloc

                    ;% rtP.adqmzv0sx0.EM_I
                    section.data(1).logicalSrcIdx = 426;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.adqmzv0sx0.EM_LowerSaturationLimit
                    section.data(2).logicalSrcIdx = 427;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.adqmzv0sx0.EM_P
                    section.data(3).logicalSrcIdx = 428;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.adqmzv0sx0.EM_UpperSaturationLimit
                    section.data(4).logicalSrcIdx = 429;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.adqmzv0sx0.Constant1_Value
                    section.data(5).logicalSrcIdx = 430;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.adqmzv0sx0.Saturation2_UpperSat
                    section.data(6).logicalSrcIdx = 431;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.adqmzv0sx0.Saturation2_LowerSat
                    section.data(7).logicalSrcIdx = 432;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.adqmzv0sx0.actf2T_Gain
                    section.data(8).logicalSrcIdx = 433;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.adqmzv0sx0.Switch1_Threshold
                    section.data(9).logicalSrcIdx = 434;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.adqmzv0sx0.Gain7_Gain
                    section.data(10).logicalSrcIdx = 435;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.adqmzv0sx0.Saturation_UpperSat
                    section.data(11).logicalSrcIdx = 436;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.adqmzv0sx0.Saturation_LowerSat
                    section.data(12).logicalSrcIdx = 437;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.adqmzv0sx0.Gain2_Gain
                    section.data(13).logicalSrcIdx = 438;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.adqmzv0sx0.Saturation1_UpperSat
                    section.data(14).logicalSrcIdx = 439;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.adqmzv0sx0.Saturation1_LowerSat
                    section.data(15).logicalSrcIdx = 440;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.adqmzv0sx0.Gain3_Gain
                    section.data(16).logicalSrcIdx = 441;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.adqmzv0sx0.Saturation_UpperSat_ollczcryiu
                    section.data(17).logicalSrcIdx = 442;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.adqmzv0sx0.Saturation_LowerSat_oypzpqvfzv
                    section.data(18).logicalSrcIdx = 443;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.adqmzv0sx0.Gain_Gain
                    section.data(19).logicalSrcIdx = 444;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.adqmzv0sx0.Saturation1_UpperSat_e5noinhxx3
                    section.data(20).logicalSrcIdx = 445;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.adqmzv0sx0.Saturation1_LowerSat_ghkwhqvuwp
                    section.data(21).logicalSrcIdx = 446;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.adqmzv0sx0.Gain5_Gain
                    section.data(22).logicalSrcIdx = 447;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.adqmzv0sx0.ZeroGain_Gain
                    section.data(23).logicalSrcIdx = 448;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.adqmzv0sx0.Gain3_Gain_cb0ak2utk4
                    section.data(24).logicalSrcIdx = 449;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.adqmzv0sx0.Saturation3_UpperSat
                    section.data(25).logicalSrcIdx = 450;
                    section.data(25).dtTransOffset = 24;

                    ;% rtP.adqmzv0sx0.Saturation3_LowerSat
                    section.data(26).logicalSrcIdx = 451;
                    section.data(26).dtTransOffset = 25;

                    ;% rtP.adqmzv0sx0.Multiply1_Gain
                    section.data(27).logicalSrcIdx = 452;
                    section.data(27).dtTransOffset = 26;

                    ;% rtP.adqmzv0sx0.Constant3_Value
                    section.data(28).logicalSrcIdx = 453;
                    section.data(28).dtTransOffset = 27;

                    ;% rtP.adqmzv0sx0.Constant_Value
                    section.data(29).logicalSrcIdx = 454;
                    section.data(29).dtTransOffset = 28;

                    ;% rtP.adqmzv0sx0.Constant1_Value_jux1hhk5qx
                    section.data(30).logicalSrcIdx = 455;
                    section.data(30).dtTransOffset = 29;

                    ;% rtP.adqmzv0sx0.DEP_incidence_Value
                    section.data(31).logicalSrcIdx = 456;
                    section.data(31).dtTransOffset = 30;

                    ;% rtP.adqmzv0sx0.Constant_Value_hl5xkc3gs1
                    section.data(32).logicalSrcIdx = 457;
                    section.data(32).dtTransOffset = 31;

            nTotData = nTotData + section.nData;
            paramMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.adqmzv0sx0.T2rpm_maxIndex
                    section.data(1).logicalSrcIdx = 458;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.adqmzv0sx0.Memory_InitialCondition
                    section.data(1).logicalSrcIdx = 459;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(20) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtP.pcwoeb21pm.x_Y0
                    section.data(1).logicalSrcIdx = 460;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.pcwoeb21pm.DistanceintoGustxLimitedtogustlengthd_IC
                    section.data(2).logicalSrcIdx = 461;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.pcwoeb21pm.DistanceintoGustxLimitedtogustlengthd_LowerSat
                    section.data(3).logicalSrcIdx = 462;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(21) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtP.fthork0k0x2.x_Y0
                    section.data(1).logicalSrcIdx = 463;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.fthork0k0x2.DistanceintoGustxLimitedtogustlengthd_IC
                    section.data(2).logicalSrcIdx = 464;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.fthork0k0x2.DistanceintoGustxLimitedtogustlengthd_LowerSat
                    section.data(3).logicalSrcIdx = 465;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.fchchnbmez.Constant_Value
                    section.data(1).logicalSrcIdx = 466;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.fchchnbmez.Constant_Value_nflcmvsqzo
                    section.data(1).logicalSrcIdx = 467;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.nyqetrz43uqkkp.Constant_Value
                    section.data(1).logicalSrcIdx = 468;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.nyqetrz43uqkkp.Constant_Value_dl1cryfboe
                    section.data(1).logicalSrcIdx = 469;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.nyqetrz43uq.Constant1_Value
                    section.data(1).logicalSrcIdx = 470;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.nyqetrz43u.Constant1_Value
                    section.data(1).logicalSrcIdx = 471;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(28) = section;
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
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 27;
        sectIdxOffset = 0;

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
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 145;
            section.data(145)  = dumData; %prealloc

                    ;% rtB.exyupufjt5
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.gt3gymd154
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.j3t4wyjy41
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 6;

                    ;% rtB.ekmklzxfox
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 22;

                    ;% rtB.kz552dd3t1
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 26;

                    ;% rtB.bopxyfw2ia
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 27;

                    ;% rtB.ecvavrybwp
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 28;

                    ;% rtB.okge55f2b5
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 29;

                    ;% rtB.n2fj5a4cso
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 30;

                    ;% rtB.li5x4km43d
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 31;

                    ;% rtB.gxhe3keu3a
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 34;

                    ;% rtB.dohtax3vu3
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 37;

                    ;% rtB.hszixujy0p
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 40;

                    ;% rtB.nn0j0nwtai
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 43;

                    ;% rtB.nupdx24lfb
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 63;

                    ;% rtB.ieaokh1oup
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 75;

                    ;% rtB.odhuccln2g
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 76;

                    ;% rtB.bw4iyihnma
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 77;

                    ;% rtB.kmxfn2bnil
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 93;

                    ;% rtB.ody4e0c4gv
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 109;

                    ;% rtB.d0gfg5onrd
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 125;

                    ;% rtB.agdfetg0qt
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 141;

                    ;% rtB.hmn4gg1bt5
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 157;

                    ;% rtB.hwfjzaa0nm
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 158;

                    ;% rtB.aeyzgmp4rb
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 159;

                    ;% rtB.d1dja0jwhm
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 160;

                    ;% rtB.jagg20wiay
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 163;

                    ;% rtB.cutvjsc51o
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 164;

                    ;% rtB.llwqqnw3ke
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 167;

                    ;% rtB.lpr3engkn0
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 168;

                    ;% rtB.adxfu05snb
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 169;

                    ;% rtB.mfsumfb52o
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 170;

                    ;% rtB.ibkkavp3uy
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 171;

                    ;% rtB.k002wprevb
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 172;

                    ;% rtB.dwtsbon1wj
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 175;

                    ;% rtB.g2lkzpk1cd
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 176;

                    ;% rtB.o3f4ir0mnt
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 177;

                    ;% rtB.phhcl0h52y
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 178;

                    ;% rtB.cmce4od5nu
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 179;

                    ;% rtB.cvpaunpk1i
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 180;

                    ;% rtB.kra5wvotxw
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 181;

                    ;% rtB.h1v0fki4wd
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 184;

                    ;% rtB.atski0fwo1
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 185;

                    ;% rtB.pzrd4nwhsl
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 186;

                    ;% rtB.hsrt1ciq4i
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 187;

                    ;% rtB.gmov3gnpox
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 188;

                    ;% rtB.onu4r5xewk
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 189;

                    ;% rtB.ehjp343jmw
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 192;

                    ;% rtB.od11ruf3th
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 193;

                    ;% rtB.oaagntandl
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 202;

                    ;% rtB.p4p4elvfjt
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 203;

                    ;% rtB.gdwsegs0yn
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 206;

                    ;% rtB.bznjqb4cys
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 209;

                    ;% rtB.hilbxeegf0
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 210;

                    ;% rtB.p0trwoq5oi
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 211;

                    ;% rtB.bq0j25ykt3
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 212;

                    ;% rtB.c5avufipwu
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 213;

                    ;% rtB.iovd14a0zv
                    section.data(58).logicalSrcIdx = 57;
                    section.data(58).dtTransOffset = 214;

                    ;% rtB.fcg44x4aqz
                    section.data(59).logicalSrcIdx = 58;
                    section.data(59).dtTransOffset = 215;

                    ;% rtB.ps23iickbr
                    section.data(60).logicalSrcIdx = 59;
                    section.data(60).dtTransOffset = 218;

                    ;% rtB.bkodm3ably
                    section.data(61).logicalSrcIdx = 60;
                    section.data(61).dtTransOffset = 221;

                    ;% rtB.fbtjhgisvg
                    section.data(62).logicalSrcIdx = 61;
                    section.data(62).dtTransOffset = 222;

                    ;% rtB.hgd1a1255d
                    section.data(63).logicalSrcIdx = 62;
                    section.data(63).dtTransOffset = 223;

                    ;% rtB.hfraqjvvj1
                    section.data(64).logicalSrcIdx = 63;
                    section.data(64).dtTransOffset = 243;

                    ;% rtB.n00gsxq4p1
                    section.data(65).logicalSrcIdx = 64;
                    section.data(65).dtTransOffset = 244;

                    ;% rtB.ixwwzqb4p2
                    section.data(66).logicalSrcIdx = 65;
                    section.data(66).dtTransOffset = 245;

                    ;% rtB.dienpmt5lk
                    section.data(67).logicalSrcIdx = 66;
                    section.data(67).dtTransOffset = 246;

                    ;% rtB.lyw5uzhlvp
                    section.data(68).logicalSrcIdx = 67;
                    section.data(68).dtTransOffset = 252;

                    ;% rtB.pxf22reogn
                    section.data(69).logicalSrcIdx = 68;
                    section.data(69).dtTransOffset = 258;

                    ;% rtB.naaosn4yn2
                    section.data(70).logicalSrcIdx = 69;
                    section.data(70).dtTransOffset = 264;

                    ;% rtB.afhieoseax
                    section.data(71).logicalSrcIdx = 70;
                    section.data(71).dtTransOffset = 270;

                    ;% rtB.niowrwikj3
                    section.data(72).logicalSrcIdx = 71;
                    section.data(72).dtTransOffset = 276;

                    ;% rtB.gbabd0z3bn
                    section.data(73).logicalSrcIdx = 72;
                    section.data(73).dtTransOffset = 282;

                    ;% rtB.hpmq1jfzli
                    section.data(74).logicalSrcIdx = 73;
                    section.data(74).dtTransOffset = 288;

                    ;% rtB.jdw5fy5uyh
                    section.data(75).logicalSrcIdx = 74;
                    section.data(75).dtTransOffset = 294;

                    ;% rtB.c0rbweqsq1
                    section.data(76).logicalSrcIdx = 75;
                    section.data(76).dtTransOffset = 295;

                    ;% rtB.agnrcu13e2
                    section.data(77).logicalSrcIdx = 76;
                    section.data(77).dtTransOffset = 296;

                    ;% rtB.ia0ra0q3ax
                    section.data(78).logicalSrcIdx = 77;
                    section.data(78).dtTransOffset = 297;

                    ;% rtB.l4whzntd2w
                    section.data(79).logicalSrcIdx = 78;
                    section.data(79).dtTransOffset = 298;

                    ;% rtB.nsqrvbi5rh
                    section.data(80).logicalSrcIdx = 79;
                    section.data(80).dtTransOffset = 299;

                    ;% rtB.kydbwk01f5
                    section.data(81).logicalSrcIdx = 80;
                    section.data(81).dtTransOffset = 300;

                    ;% rtB.g3dy1b3uqu
                    section.data(82).logicalSrcIdx = 81;
                    section.data(82).dtTransOffset = 301;

                    ;% rtB.dkmnirebs0
                    section.data(83).logicalSrcIdx = 82;
                    section.data(83).dtTransOffset = 302;

                    ;% rtB.avgj00fc45
                    section.data(84).logicalSrcIdx = 83;
                    section.data(84).dtTransOffset = 305;

                    ;% rtB.eezj4zgsj4
                    section.data(85).logicalSrcIdx = 84;
                    section.data(85).dtTransOffset = 308;

                    ;% rtB.m1qwau1ibb
                    section.data(86).logicalSrcIdx = 85;
                    section.data(86).dtTransOffset = 311;

                    ;% rtB.nci1mnnllt
                    section.data(87).logicalSrcIdx = 86;
                    section.data(87).dtTransOffset = 314;

                    ;% rtB.elv40zm3eo
                    section.data(88).logicalSrcIdx = 87;
                    section.data(88).dtTransOffset = 315;

                    ;% rtB.jopjoprq0c
                    section.data(89).logicalSrcIdx = 88;
                    section.data(89).dtTransOffset = 316;

                    ;% rtB.ku55m1jm2d
                    section.data(90).logicalSrcIdx = 89;
                    section.data(90).dtTransOffset = 317;

                    ;% rtB.af22xidizc
                    section.data(91).logicalSrcIdx = 90;
                    section.data(91).dtTransOffset = 318;

                    ;% rtB.bifocupq14
                    section.data(92).logicalSrcIdx = 91;
                    section.data(92).dtTransOffset = 319;

                    ;% rtB.bxtdurt4xq
                    section.data(93).logicalSrcIdx = 92;
                    section.data(93).dtTransOffset = 320;

                    ;% rtB.bdfwgn2f4t
                    section.data(94).logicalSrcIdx = 93;
                    section.data(94).dtTransOffset = 321;

                    ;% rtB.izwq3m54sy
                    section.data(95).logicalSrcIdx = 94;
                    section.data(95).dtTransOffset = 322;

                    ;% rtB.mhiuaswy01
                    section.data(96).logicalSrcIdx = 95;
                    section.data(96).dtTransOffset = 323;

                    ;% rtB.hwhq5yb2fg
                    section.data(97).logicalSrcIdx = 96;
                    section.data(97).dtTransOffset = 324;

                    ;% rtB.l1dfj2jhio
                    section.data(98).logicalSrcIdx = 97;
                    section.data(98).dtTransOffset = 325;

                    ;% rtB.l0khcdm5vj
                    section.data(99).logicalSrcIdx = 98;
                    section.data(99).dtTransOffset = 326;

                    ;% rtB.hc3pucpzoc
                    section.data(100).logicalSrcIdx = 99;
                    section.data(100).dtTransOffset = 327;

                    ;% rtB.h1pryicb3f
                    section.data(101).logicalSrcIdx = 100;
                    section.data(101).dtTransOffset = 328;

                    ;% rtB.djshdafk4a
                    section.data(102).logicalSrcIdx = 101;
                    section.data(102).dtTransOffset = 329;

                    ;% rtB.jurla4fp4a
                    section.data(103).logicalSrcIdx = 102;
                    section.data(103).dtTransOffset = 330;

                    ;% rtB.pchtyrudar
                    section.data(104).logicalSrcIdx = 103;
                    section.data(104).dtTransOffset = 331;

                    ;% rtB.k0wfvnkgwy
                    section.data(105).logicalSrcIdx = 104;
                    section.data(105).dtTransOffset = 340;

                    ;% rtB.armozr15x5
                    section.data(106).logicalSrcIdx = 105;
                    section.data(106).dtTransOffset = 349;

                    ;% rtB.dcirnuyxde
                    section.data(107).logicalSrcIdx = 106;
                    section.data(107).dtTransOffset = 358;

                    ;% rtB.jferaaeyyn
                    section.data(108).logicalSrcIdx = 107;
                    section.data(108).dtTransOffset = 370;

                    ;% rtB.jemxdtgsel
                    section.data(109).logicalSrcIdx = 108;
                    section.data(109).dtTransOffset = 371;

                    ;% rtB.awnwv0frb5
                    section.data(110).logicalSrcIdx = 109;
                    section.data(110).dtTransOffset = 372;

                    ;% rtB.on14h4dmvl
                    section.data(111).logicalSrcIdx = 110;
                    section.data(111).dtTransOffset = 375;

                    ;% rtB.lrtymnw4xi
                    section.data(112).logicalSrcIdx = 111;
                    section.data(112).dtTransOffset = 376;

                    ;% rtB.fnmgllmgqx
                    section.data(113).logicalSrcIdx = 112;
                    section.data(113).dtTransOffset = 377;

                    ;% rtB.fqvqdt4rd2
                    section.data(114).logicalSrcIdx = 113;
                    section.data(114).dtTransOffset = 378;

                    ;% rtB.jmxba5skz5
                    section.data(115).logicalSrcIdx = 114;
                    section.data(115).dtTransOffset = 379;

                    ;% rtB.pr1vt54ko4
                    section.data(116).logicalSrcIdx = 115;
                    section.data(116).dtTransOffset = 380;

                    ;% rtB.jygnbcsqf1
                    section.data(117).logicalSrcIdx = 116;
                    section.data(117).dtTransOffset = 383;

                    ;% rtB.lwvqxcae23
                    section.data(118).logicalSrcIdx = 117;
                    section.data(118).dtTransOffset = 386;

                    ;% rtB.f1a2rfeuz1
                    section.data(119).logicalSrcIdx = 118;
                    section.data(119).dtTransOffset = 387;

                    ;% rtB.ih10mokqjs
                    section.data(120).logicalSrcIdx = 119;
                    section.data(120).dtTransOffset = 388;

                    ;% rtB.g344blsojt
                    section.data(121).logicalSrcIdx = 120;
                    section.data(121).dtTransOffset = 389;

                    ;% rtB.grblrau4l1
                    section.data(122).logicalSrcIdx = 121;
                    section.data(122).dtTransOffset = 390;

                    ;% rtB.mythzqzjez
                    section.data(123).logicalSrcIdx = 122;
                    section.data(123).dtTransOffset = 391;

                    ;% rtB.cdxkdrlzzm
                    section.data(124).logicalSrcIdx = 123;
                    section.data(124).dtTransOffset = 394;

                    ;% rtB.ffkpsdx0zr
                    section.data(125).logicalSrcIdx = 124;
                    section.data(125).dtTransOffset = 397;

                    ;% rtB.ftrxuf0i4a
                    section.data(126).logicalSrcIdx = 125;
                    section.data(126).dtTransOffset = 398;

                    ;% rtB.hqi2kczfkw
                    section.data(127).logicalSrcIdx = 126;
                    section.data(127).dtTransOffset = 399;

                    ;% rtB.lpx2s5ac0u
                    section.data(128).logicalSrcIdx = 127;
                    section.data(128).dtTransOffset = 400;

                    ;% rtB.pmom2ene5w
                    section.data(129).logicalSrcIdx = 128;
                    section.data(129).dtTransOffset = 401;

                    ;% rtB.njlxqs1uc4
                    section.data(130).logicalSrcIdx = 129;
                    section.data(130).dtTransOffset = 402;

                    ;% rtB.e32n1qjlbz
                    section.data(131).logicalSrcIdx = 130;
                    section.data(131).dtTransOffset = 405;

                    ;% rtB.higayyxcv3
                    section.data(132).logicalSrcIdx = 131;
                    section.data(132).dtTransOffset = 408;

                    ;% rtB.djejdif2w5
                    section.data(133).logicalSrcIdx = 132;
                    section.data(133).dtTransOffset = 409;

                    ;% rtB.l2pt0kefdc
                    section.data(134).logicalSrcIdx = 133;
                    section.data(134).dtTransOffset = 410;

                    ;% rtB.dkodtfhso0
                    section.data(135).logicalSrcIdx = 134;
                    section.data(135).dtTransOffset = 413;

                    ;% rtB.lw0kvssqse
                    section.data(136).logicalSrcIdx = 135;
                    section.data(136).dtTransOffset = 414;

                    ;% rtB.nos3a2bbnv
                    section.data(137).logicalSrcIdx = 136;
                    section.data(137).dtTransOffset = 415;

                    ;% rtB.lhydxe5abe
                    section.data(138).logicalSrcIdx = 137;
                    section.data(138).dtTransOffset = 416;

                    ;% rtB.pr1zzcknox
                    section.data(139).logicalSrcIdx = 138;
                    section.data(139).dtTransOffset = 417;

                    ;% rtB.btiigxjvj2
                    section.data(140).logicalSrcIdx = 139;
                    section.data(140).dtTransOffset = 418;

                    ;% rtB.lbzmmcd5bg
                    section.data(141).logicalSrcIdx = 140;
                    section.data(141).dtTransOffset = 421;

                    ;% rtB.f0lcoipiql
                    section.data(142).logicalSrcIdx = 141;
                    section.data(142).dtTransOffset = 422;

                    ;% rtB.nhnvabjkuz
                    section.data(143).logicalSrcIdx = 142;
                    section.data(143).dtTransOffset = 442;

                    ;% rtB.anhsgyheay
                    section.data(144).logicalSrcIdx = 143;
                    section.data(144).dtTransOffset = 454;

                    ;% rtB.iu2wb1r235
                    section.data(145).logicalSrcIdx = 144;
                    section.data(145).dtTransOffset = 466;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtB.pgacreyak0
                    section.data(1).logicalSrcIdx = 145;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.lcfixu2lfk
                    section.data(2).logicalSrcIdx = 146;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.mb1y0b3eym
                    section.data(3).logicalSrcIdx = 147;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.lj1ecmy3sj
                    section.data(4).logicalSrcIdx = 148;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.nj3xuut2fh
                    section.data(5).logicalSrcIdx = 149;
                    section.data(5).dtTransOffset = 4;

                    ;% rtB.ngy3pgy40m
                    section.data(6).logicalSrcIdx = 150;
                    section.data(6).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 27;
            section.data(27)  = dumData; %prealloc

                    ;% rtB.jrm5mulpgo
                    section.data(1).logicalSrcIdx = 151;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.kp4feo544t
                    section.data(2).logicalSrcIdx = 152;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.korrwukkg3
                    section.data(3).logicalSrcIdx = 153;
                    section.data(3).dtTransOffset = 6;

                    ;% rtB.buybsypzuh
                    section.data(4).logicalSrcIdx = 154;
                    section.data(4).dtTransOffset = 13;

                    ;% rtB.kdl2q2ktlu
                    section.data(5).logicalSrcIdx = 155;
                    section.data(5).dtTransOffset = 14;

                    ;% rtB.bflkh3tw3c
                    section.data(6).logicalSrcIdx = 156;
                    section.data(6).dtTransOffset = 15;

                    ;% rtB.be1wst1pkg
                    section.data(7).logicalSrcIdx = 157;
                    section.data(7).dtTransOffset = 36;

                    ;% rtB.gefiy4un3d
                    section.data(8).logicalSrcIdx = 158;
                    section.data(8).dtTransOffset = 37;

                    ;% rtB.lif0jqyjen
                    section.data(9).logicalSrcIdx = 159;
                    section.data(9).dtTransOffset = 38;

                    ;% rtB.ln5blvjdm3
                    section.data(10).logicalSrcIdx = 160;
                    section.data(10).dtTransOffset = 59;

                    ;% rtB.ge01nkozzs
                    section.data(11).logicalSrcIdx = 161;
                    section.data(11).dtTransOffset = 75;

                    ;% rtB.o0icr3ysdn
                    section.data(12).logicalSrcIdx = 162;
                    section.data(12).dtTransOffset = 91;

                    ;% rtB.dlawj1hfkq
                    section.data(13).logicalSrcIdx = 163;
                    section.data(13).dtTransOffset = 139;

                    ;% rtB.krmhpaiwtk
                    section.data(14).logicalSrcIdx = 164;
                    section.data(14).dtTransOffset = 142;

                    ;% rtB.phywd5jekf
                    section.data(15).logicalSrcIdx = 165;
                    section.data(15).dtTransOffset = 145;

                    ;% rtB.ar3fw3fuom
                    section.data(16).logicalSrcIdx = 166;
                    section.data(16).dtTransOffset = 146;

                    ;% rtB.ckez2fhnc0
                    section.data(17).logicalSrcIdx = 167;
                    section.data(17).dtTransOffset = 147;

                    ;% rtB.ayq52soaqw
                    section.data(18).logicalSrcIdx = 168;
                    section.data(18).dtTransOffset = 148;

                    ;% rtB.byhpdluumb
                    section.data(19).logicalSrcIdx = 169;
                    section.data(19).dtTransOffset = 169;

                    ;% rtB.ayq52soaqwz
                    section.data(20).logicalSrcIdx = 170;
                    section.data(20).dtTransOffset = 190;

                    ;% rtB.byhpdluumbu
                    section.data(21).logicalSrcIdx = 171;
                    section.data(21).dtTransOffset = 211;

                    ;% rtB.byhpdluumbuo
                    section.data(22).logicalSrcIdx = 172;
                    section.data(22).dtTransOffset = 232;

                    ;% rtB.cfz24gonbx
                    section.data(23).logicalSrcIdx = 173;
                    section.data(23).dtTransOffset = 280;

                    ;% rtB.nmxk2xrfk3
                    section.data(24).logicalSrcIdx = 174;
                    section.data(24).dtTransOffset = 294;

                    ;% rtB.atgyr3lfo3
                    section.data(25).logicalSrcIdx = 175;
                    section.data(25).dtTransOffset = 308;

                    ;% rtB.cfz24gonbxg
                    section.data(26).logicalSrcIdx = 176;
                    section.data(26).dtTransOffset = 324;

                    ;% rtB.nmxk2xrfk3z
                    section.data(27).logicalSrcIdx = 177;
                    section.data(27).dtTransOffset = 340;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtB.gtlyl45i3j
                    section.data(1).logicalSrcIdx = 178;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.o0njsmigyn
                    section.data(2).logicalSrcIdx = 179;
                    section.data(2).dtTransOffset = 509;

                    ;% rtB.hjcw1qdlw2
                    section.data(3).logicalSrcIdx = 180;
                    section.data(3).dtTransOffset = 1018;

                    ;% rtB.iffp5o1pbp
                    section.data(4).logicalSrcIdx = 181;
                    section.data(4).dtTransOffset = 1063;

                    ;% rtB.kno2d54iit
                    section.data(5).logicalSrcIdx = 182;
                    section.data(5).dtTransOffset = 1572;

                    ;% rtB.bqi10o4hpx
                    section.data(6).logicalSrcIdx = 183;
                    section.data(6).dtTransOffset = 2081;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtB.n3u1rxuv5j
                    section.data(1).logicalSrcIdx = 185;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.hetdp5lb3h
                    section.data(2).logicalSrcIdx = 186;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.h5anqi052g
                    section.data(3).logicalSrcIdx = 187;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.fvsr3tltfl
                    section.data(4).logicalSrcIdx = 188;
                    section.data(4).dtTransOffset = 3;

                    ;% rtB.dzk03qgr1o
                    section.data(5).logicalSrcIdx = 189;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.hztlwupntw.h11nwvgfxj
                    section.data(1).logicalSrcIdx = 190;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.n1ybyykngv.h11nwvgfxj
                    section.data(1).logicalSrcIdx = 191;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jek5zaxern.gz0squozgl
                    section.data(1).logicalSrcIdx = 192;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.nikuyjvr0y.gz0squozgl
                    section.data(1).logicalSrcIdx = 193;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.enohy5yaap.gz0squozgl
                    section.data(1).logicalSrcIdx = 194;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.pookhwl2ri.hr4wpt01um
                    section.data(1).logicalSrcIdx = 195;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.hl5ibqcu3w.hr4wpt01um
                    section.data(1).logicalSrcIdx = 196;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.dffuptpbcz.e1wak2s0nn
                    section.data(1).logicalSrcIdx = 197;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.bd32gk0ocy.e1wak2s0nn
                    section.data(1).logicalSrcIdx = 198;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(14) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.leuhdrxpbe.ggmvjtadg3
                    section.data(1).logicalSrcIdx = 199;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.leuhdrxpbe.jr3yr4ixei
                    section.data(2).logicalSrcIdx = 200;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(15) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.csf3emrtxr.ggmvjtadg3
                    section.data(1).logicalSrcIdx = 201;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.csf3emrtxr.jr3yr4ixei
                    section.data(2).logicalSrcIdx = 202;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(16) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.jvaexa3o5a.ggmvjtadg3
                    section.data(1).logicalSrcIdx = 203;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.jvaexa3o5a.jr3yr4ixei
                    section.data(2).logicalSrcIdx = 204;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(17) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtB.adqmzv0sx0[11].ibnqksi5kc
                    section.data(1).logicalSrcIdx = 205;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.adqmzv0sx0[11].jagzqtugld
                    section.data(2).logicalSrcIdx = 206;
                    section.data(2).dtTransOffset = 1;

                    ;% rtB.adqmzv0sx0[11].dfpeduhr4c
                    section.data(3).logicalSrcIdx = 207;
                    section.data(3).dtTransOffset = 2;

                    ;% rtB.adqmzv0sx0[11].ex2xojeend
                    section.data(4).logicalSrcIdx = 208;
                    section.data(4).dtTransOffset = 5;

                    ;% rtB.adqmzv0sx0[11].n52zpi4j4s
                    section.data(5).logicalSrcIdx = 209;
                    section.data(5).dtTransOffset = 6;

                    ;% rtB.adqmzv0sx0[11].dbnx540oz1
                    section.data(6).logicalSrcIdx = 210;
                    section.data(6).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            sigMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.adqmzv0sx0[11].aox0khugvh
                    section.data(1).logicalSrcIdx = 211;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(19) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.adqmzv0sx0[11].cgxtlo5ezj
                    section.data(1).logicalSrcIdx = 212;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.adqmzv0sx0[11].hqlowwzkov
                    section.data(2).logicalSrcIdx = 213;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.pcwoeb21pm.c1tiif3ujm
                    section.data(1).logicalSrcIdx = 214;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.fthork0k0x2.c1tiif3ujm
                    section.data(1).logicalSrcIdx = 215;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(22) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.nyqetrz43uqkkpi[6].jqzydkhuci
                    section.data(1).logicalSrcIdx = 216;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.nyqetrz43uqkkpi[6].gg011l2nji
                    section.data(2).logicalSrcIdx = 217;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(23) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.nyqetrz43uqkk[6].d2kygac014
                    section.data(1).logicalSrcIdx = 218;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.nyqetrz43uqkk[6].dbot5mi30f
                    section.data(2).logicalSrcIdx = 219;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(24) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.nyqetrz43uqk[15].f5l1thfo3b
                    section.data(1).logicalSrcIdx = 220;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.nyqetrz43uqk[15].a0tbi33tik
                    section.data(2).logicalSrcIdx = 221;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(25) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.nyqetrz43uq[13].g2bz2muoaw
                    section.data(1).logicalSrcIdx = 222;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.nyqetrz43uq[13].lkowsjx5yc
                    section.data(2).logicalSrcIdx = 223;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(26) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.nyqetrz43u[15].kl452g3br4
                    section.data(1).logicalSrcIdx = 224;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.nyqetrz43u[15].ico5bo4shp
                    section.data(2).logicalSrcIdx = 225;
                    section.data(2).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(27) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 50;
        sectIdxOffset = 27;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 57;
            section.data(57)  = dumData; %prealloc

                    ;% rtDW.g540jxiiax
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.crxd5n2r3l
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 100;

                    ;% rtDW.fx230yq5sl
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 200;

                    ;% rtDW.kvnpr153yy
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 205;

                    ;% rtDW.jhfnsaqhxz
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 210;

                    ;% rtDW.lnmqg4h42q
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 215;

                    ;% rtDW.jsnr5tvela
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 220;

                    ;% rtDW.buecpeq4re
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 225;

                    ;% rtDW.asespk50pt
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 230;

                    ;% rtDW.pmmx1tycaz
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 235;

                    ;% rtDW.e5trjt2azz
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 240;

                    ;% rtDW.eqbrrfiebl
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 245;

                    ;% rtDW.fkbachhibk
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 260;

                    ;% rtDW.oaqzp5s2cy
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 305;

                    ;% rtDW.plokoj1iat
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 310;

                    ;% rtDW.p3n5g3torf
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 325;

                    ;% rtDW.avagxvnwf5
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 340;

                    ;% rtDW.lkru3wc4bj
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 355;

                    ;% rtDW.pwrdd5kibs
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 360;

                    ;% rtDW.erskmg5gj1
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 365;

                    ;% rtDW.jj43i52zwn
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 370;

                    ;% rtDW.pagqs1iwpr
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 375;

                    ;% rtDW.hvagkay33y
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 380;

                    ;% rtDW.eoz1jvwwoq
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 385;

                    ;% rtDW.jgluwzgfp1
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 390;

                    ;% rtDW.cpjltmd3l2
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 395;

                    ;% rtDW.dcos1gkpc2
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 400;

                    ;% rtDW.eypbisuusv
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 405;

                    ;% rtDW.ezpcxtf0ip
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 410;

                    ;% rtDW.ookott5jvl
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 415;

                    ;% rtDW.h3h1h5xjyq
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 420;

                    ;% rtDW.aadveypr3e
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 425;

                    ;% rtDW.nwwie5t5of
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 430;

                    ;% rtDW.keywsrry0q
                    section.data(34).logicalSrcIdx = 33;
                    section.data(34).dtTransOffset = 431;

                    ;% rtDW.faxkrudp40
                    section.data(35).logicalSrcIdx = 34;
                    section.data(35).dtTransOffset = 432;

                    ;% rtDW.m4a0ukvmhq
                    section.data(36).logicalSrcIdx = 35;
                    section.data(36).dtTransOffset = 569;

                    ;% rtDW.mbrgrjucym
                    section.data(37).logicalSrcIdx = 36;
                    section.data(37).dtTransOffset = 706;

                    ;% rtDW.kedw3dybgq
                    section.data(38).logicalSrcIdx = 37;
                    section.data(38).dtTransOffset = 843;

                    ;% rtDW.abjojyrz15
                    section.data(39).logicalSrcIdx = 38;
                    section.data(39).dtTransOffset = 844;

                    ;% rtDW.ft5azbdazn
                    section.data(40).logicalSrcIdx = 39;
                    section.data(40).dtTransOffset = 981;

                    ;% rtDW.m05hfkvpqz
                    section.data(41).logicalSrcIdx = 40;
                    section.data(41).dtTransOffset = 1118;

                    ;% rtDW.ksy2wwjv20
                    section.data(42).logicalSrcIdx = 41;
                    section.data(42).dtTransOffset = 1255;

                    ;% rtDW.axqu4ckdky
                    section.data(43).logicalSrcIdx = 42;
                    section.data(43).dtTransOffset = 1392;

                    ;% rtDW.f00y3b0qin
                    section.data(44).logicalSrcIdx = 43;
                    section.data(44).dtTransOffset = 1529;

                    ;% rtDW.ehnerh2sch
                    section.data(45).logicalSrcIdx = 44;
                    section.data(45).dtTransOffset = 1666;

                    ;% rtDW.h52cjzwtlm
                    section.data(46).logicalSrcIdx = 45;
                    section.data(46).dtTransOffset = 1803;

                    ;% rtDW.ktsj2nkchd
                    section.data(47).logicalSrcIdx = 46;
                    section.data(47).dtTransOffset = 1940;

                    ;% rtDW.hshhxf1iwg
                    section.data(48).logicalSrcIdx = 47;
                    section.data(48).dtTransOffset = 1941;

                    ;% rtDW.fsed3lqtd2
                    section.data(49).logicalSrcIdx = 48;
                    section.data(49).dtTransOffset = 2078;

                    ;% rtDW.oy300njhw2
                    section.data(50).logicalSrcIdx = 49;
                    section.data(50).dtTransOffset = 2215;

                    ;% rtDW.ie2l444zba
                    section.data(51).logicalSrcIdx = 50;
                    section.data(51).dtTransOffset = 2218;

                    ;% rtDW.fr2fpc1qxz
                    section.data(52).logicalSrcIdx = 51;
                    section.data(52).dtTransOffset = 2221;

                    ;% rtDW.ilac1ylth3
                    section.data(53).logicalSrcIdx = 52;
                    section.data(53).dtTransOffset = 2224;

                    ;% rtDW.lwsgjestu3
                    section.data(54).logicalSrcIdx = 53;
                    section.data(54).dtTransOffset = 2233;

                    ;% rtDW.o4nasosvnh
                    section.data(55).logicalSrcIdx = 54;
                    section.data(55).dtTransOffset = 2370;

                    ;% rtDW.nevgeggqm5.modelTStart
                    section.data(56).logicalSrcIdx = 55;
                    section.data(56).dtTransOffset = 2507;

                    ;% rtDW.lq4e3tdaf4.modelTStart
                    section.data(57).logicalSrcIdx = 56;
                    section.data(57).dtTransOffset = 2508;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 55;
            section.data(55)  = dumData; %prealloc

                    ;% rtDW.c4dytoevnt.LoggedData
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.hp20t3vsp0.LoggedData
                    section.data(2).logicalSrcIdx = 58;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.a1p5mmdhor.TUbufferPtrs
                    section.data(3).logicalSrcIdx = 59;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.d5j1ciynjn.TUbufferPtrs
                    section.data(4).logicalSrcIdx = 60;
                    section.data(4).dtTransOffset = 34;

                    ;% rtDW.dhi5a05pfe.LoggedData
                    section.data(5).logicalSrcIdx = 61;
                    section.data(5).dtTransOffset = 66;

                    ;% rtDW.pcsd1zoeme.LoggedData
                    section.data(6).logicalSrcIdx = 62;
                    section.data(6).dtTransOffset = 69;

                    ;% rtDW.iazcz4ksei.LoggedData
                    section.data(7).logicalSrcIdx = 63;
                    section.data(7).dtTransOffset = 72;

                    ;% rtDW.psp0p5103u.LoggedData
                    section.data(8).logicalSrcIdx = 64;
                    section.data(8).dtTransOffset = 75;

                    ;% rtDW.km5zthkh0j.LoggedData
                    section.data(9).logicalSrcIdx = 65;
                    section.data(9).dtTransOffset = 78;

                    ;% rtDW.ipldhfa011.LoggedData
                    section.data(10).logicalSrcIdx = 66;
                    section.data(10).dtTransOffset = 81;

                    ;% rtDW.j4e1wtbi0o.LoggedData
                    section.data(11).logicalSrcIdx = 67;
                    section.data(11).dtTransOffset = 84;

                    ;% rtDW.afn4mecjjd.LoggedData
                    section.data(12).logicalSrcIdx = 68;
                    section.data(12).dtTransOffset = 86;

                    ;% rtDW.dzukxciamp.AQHandles
                    section.data(13).logicalSrcIdx = 69;
                    section.data(13).dtTransOffset = 88;

                    ;% rtDW.oumnpiegvc.AQHandles
                    section.data(14).logicalSrcIdx = 70;
                    section.data(14).dtTransOffset = 89;

                    ;% rtDW.kmqxlkx3v2.AQHandles
                    section.data(15).logicalSrcIdx = 71;
                    section.data(15).dtTransOffset = 90;

                    ;% rtDW.oszdennjt4.AQHandles
                    section.data(16).logicalSrcIdx = 72;
                    section.data(16).dtTransOffset = 91;

                    ;% rtDW.glhrtguzli.AQHandles
                    section.data(17).logicalSrcIdx = 73;
                    section.data(17).dtTransOffset = 92;

                    ;% rtDW.m4f243pj4m.LoggedData
                    section.data(18).logicalSrcIdx = 74;
                    section.data(18).dtTransOffset = 93;

                    ;% rtDW.cbfh0ipqzy.LoggedData
                    section.data(19).logicalSrcIdx = 75;
                    section.data(19).dtTransOffset = 96;

                    ;% rtDW.dzukxciampy.AQHandles
                    section.data(20).logicalSrcIdx = 76;
                    section.data(20).dtTransOffset = 99;

                    ;% rtDW.dzukxciampy4.AQHandles
                    section.data(21).logicalSrcIdx = 77;
                    section.data(21).dtTransOffset = 100;

                    ;% rtDW.dzukxciampy43.AQHandles
                    section.data(22).logicalSrcIdx = 78;
                    section.data(22).dtTransOffset = 101;

                    ;% rtDW.dzukxciampy430.AQHandles
                    section.data(23).logicalSrcIdx = 79;
                    section.data(23).dtTransOffset = 102;

                    ;% rtDW.oumnpiegvcp.AQHandles
                    section.data(24).logicalSrcIdx = 80;
                    section.data(24).dtTransOffset = 103;

                    ;% rtDW.kmqxlkx3v2q.AQHandles
                    section.data(25).logicalSrcIdx = 81;
                    section.data(25).dtTransOffset = 104;

                    ;% rtDW.oszdennjt4x.AQHandles
                    section.data(26).logicalSrcIdx = 82;
                    section.data(26).dtTransOffset = 105;

                    ;% rtDW.glhrtguzlib.AQHandles
                    section.data(27).logicalSrcIdx = 83;
                    section.data(27).dtTransOffset = 106;

                    ;% rtDW.a01trbqc4k.AQHandles
                    section.data(28).logicalSrcIdx = 84;
                    section.data(28).dtTransOffset = 107;

                    ;% rtDW.m3daqdrf13.LoggedData
                    section.data(29).logicalSrcIdx = 85;
                    section.data(29).dtTransOffset = 108;

                    ;% rtDW.avgcen3t22.LoggedData
                    section.data(30).logicalSrcIdx = 86;
                    section.data(30).dtTransOffset = 111;

                    ;% rtDW.bjo4j2im3p.LoggedData
                    section.data(31).logicalSrcIdx = 87;
                    section.data(31).dtTransOffset = 114;

                    ;% rtDW.nnuoj3bvrf.LoggedData
                    section.data(32).logicalSrcIdx = 88;
                    section.data(32).dtTransOffset = 115;

                    ;% rtDW.dzukxciampy430g.AQHandles
                    section.data(33).logicalSrcIdx = 89;
                    section.data(33).dtTransOffset = 116;

                    ;% rtDW.lonw1kej4h.LoggedData
                    section.data(34).logicalSrcIdx = 90;
                    section.data(34).dtTransOffset = 117;

                    ;% rtDW.hpymvgtvx5.AQHandles
                    section.data(35).logicalSrcIdx = 91;
                    section.data(35).dtTransOffset = 118;

                    ;% rtDW.dg14esoudi.LoggedData
                    section.data(36).logicalSrcIdx = 92;
                    section.data(36).dtTransOffset = 119;

                    ;% rtDW.kk0xhzsxeo.LoggedData
                    section.data(37).logicalSrcIdx = 93;
                    section.data(37).dtTransOffset = 120;

                    ;% rtDW.kj4zwd1p12.LoggedData
                    section.data(38).logicalSrcIdx = 94;
                    section.data(38).dtTransOffset = 121;

                    ;% rtDW.jcdaiyxqmm.LoggedData
                    section.data(39).logicalSrcIdx = 95;
                    section.data(39).dtTransOffset = 122;

                    ;% rtDW.jm5fiea1a2.LoggedData
                    section.data(40).logicalSrcIdx = 96;
                    section.data(40).dtTransOffset = 124;

                    ;% rtDW.mouxkhwhvf.LoggedData
                    section.data(41).logicalSrcIdx = 97;
                    section.data(41).dtTransOffset = 125;

                    ;% rtDW.j1nymsch2a.LoggedData
                    section.data(42).logicalSrcIdx = 98;
                    section.data(42).dtTransOffset = 126;

                    ;% rtDW.dckcas4wkr.LoggedData
                    section.data(43).logicalSrcIdx = 99;
                    section.data(43).dtTransOffset = 127;

                    ;% rtDW.jalebwub1e.LoggedData
                    section.data(44).logicalSrcIdx = 100;
                    section.data(44).dtTransOffset = 128;

                    ;% rtDW.o5c5s3r4a5.LoggedData
                    section.data(45).logicalSrcIdx = 101;
                    section.data(45).dtTransOffset = 130;

                    ;% rtDW.c0smk3nyqc.LoggedData
                    section.data(46).logicalSrcIdx = 102;
                    section.data(46).dtTransOffset = 131;

                    ;% rtDW.kq4bolygly.LoggedData
                    section.data(47).logicalSrcIdx = 103;
                    section.data(47).dtTransOffset = 132;

                    ;% rtDW.bb4yc0itxm.LoggedData
                    section.data(48).logicalSrcIdx = 104;
                    section.data(48).dtTransOffset = 133;

                    ;% rtDW.kppaiyfjx0.LoggedData
                    section.data(49).logicalSrcIdx = 105;
                    section.data(49).dtTransOffset = 134;

                    ;% rtDW.pa1gipcb5b.LoggedData
                    section.data(50).logicalSrcIdx = 106;
                    section.data(50).dtTransOffset = 136;

                    ;% rtDW.dkmloaeklk.LoggedData
                    section.data(51).logicalSrcIdx = 107;
                    section.data(51).dtTransOffset = 137;

                    ;% rtDW.gmerynjpyv.LoggedData
                    section.data(52).logicalSrcIdx = 108;
                    section.data(52).dtTransOffset = 138;

                    ;% rtDW.ccx3cclwb5.LoggedData
                    section.data(53).logicalSrcIdx = 109;
                    section.data(53).dtTransOffset = 142;

                    ;% rtDW.jtu0h5fs3x.LoggedData
                    section.data(54).logicalSrcIdx = 110;
                    section.data(54).dtTransOffset = 143;

                    ;% rtDW.c4eormxcf2.LoggedData
                    section.data(55).logicalSrcIdx = 111;
                    section.data(55).dtTransOffset = 144;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.ml2zybgolh
                    section.data(1).logicalSrcIdx = 112;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.nndt0j2iyw
                    section.data(2).logicalSrcIdx = 113;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.oxzbnowmim
                    section.data(3).logicalSrcIdx = 114;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.csd33umrye
                    section.data(4).logicalSrcIdx = 115;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.odfy0ab2zu
                    section.data(5).logicalSrcIdx = 116;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.piktw1sptf
                    section.data(6).logicalSrcIdx = 117;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 33;
            section.data(33)  = dumData; %prealloc

                    ;% rtDW.iinforci3b
                    section.data(1).logicalSrcIdx = 118;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.onpp1osnf1
                    section.data(2).logicalSrcIdx = 119;
                    section.data(2).dtTransOffset = 4;

                    ;% rtDW.knywr3cygt
                    section.data(3).logicalSrcIdx = 120;
                    section.data(3).dtTransOffset = 5;

                    ;% rtDW.bxxehqrfhk
                    section.data(4).logicalSrcIdx = 121;
                    section.data(4).dtTransOffset = 10;

                    ;% rtDW.lybiwzq15a
                    section.data(5).logicalSrcIdx = 122;
                    section.data(5).dtTransOffset = 15;

                    ;% rtDW.hhpqcwloh0
                    section.data(6).logicalSrcIdx = 123;
                    section.data(6).dtTransOffset = 20;

                    ;% rtDW.hxdxaozqh1
                    section.data(7).logicalSrcIdx = 124;
                    section.data(7).dtTransOffset = 21;

                    ;% rtDW.fknte5kkos
                    section.data(8).logicalSrcIdx = 125;
                    section.data(8).dtTransOffset = 23;

                    ;% rtDW.mnfw2imvdw
                    section.data(9).logicalSrcIdx = 126;
                    section.data(9).dtTransOffset = 25;

                    ;% rtDW.felqedgyx1
                    section.data(10).logicalSrcIdx = 127;
                    section.data(10).dtTransOffset = 27;

                    ;% rtDW.knvjdfedfb
                    section.data(11).logicalSrcIdx = 128;
                    section.data(11).dtTransOffset = 28;

                    ;% rtDW.apjnubwssp
                    section.data(12).logicalSrcIdx = 129;
                    section.data(12).dtTransOffset = 33;

                    ;% rtDW.ptu3l2ehpk
                    section.data(13).logicalSrcIdx = 130;
                    section.data(13).dtTransOffset = 38;

                    ;% rtDW.ebmg2d0djd
                    section.data(14).logicalSrcIdx = 131;
                    section.data(14).dtTransOffset = 43;

                    ;% rtDW.nmrn1j5ohh
                    section.data(15).logicalSrcIdx = 132;
                    section.data(15).dtTransOffset = 44;

                    ;% rtDW.hl5ux0u3e5
                    section.data(16).logicalSrcIdx = 133;
                    section.data(16).dtTransOffset = 46;

                    ;% rtDW.kywikzuq0z
                    section.data(17).logicalSrcIdx = 134;
                    section.data(17).dtTransOffset = 48;

                    ;% rtDW.op4s5nmfn0
                    section.data(18).logicalSrcIdx = 135;
                    section.data(18).dtTransOffset = 50;

                    ;% rtDW.p3qcu4kyf3
                    section.data(19).logicalSrcIdx = 136;
                    section.data(19).dtTransOffset = 66;

                    ;% rtDW.d1rjlxqbuf
                    section.data(20).logicalSrcIdx = 137;
                    section.data(20).dtTransOffset = 82;

                    ;% rtDW.g130c2x32o
                    section.data(21).logicalSrcIdx = 138;
                    section.data(21).dtTransOffset = 98;

                    ;% rtDW.dssqgth4gt
                    section.data(22).logicalSrcIdx = 139;
                    section.data(22).dtTransOffset = 114;

                    ;% rtDW.erz4us2nfk
                    section.data(23).logicalSrcIdx = 140;
                    section.data(23).dtTransOffset = 130;

                    ;% rtDW.fyjcynthf1
                    section.data(24).logicalSrcIdx = 141;
                    section.data(24).dtTransOffset = 146;

                    ;% rtDW.acn3fu00s1
                    section.data(25).logicalSrcIdx = 142;
                    section.data(25).dtTransOffset = 162;

                    ;% rtDW.itcccsf0ct
                    section.data(26).logicalSrcIdx = 143;
                    section.data(26).dtTransOffset = 178;

                    ;% rtDW.lipbrcbfzk
                    section.data(27).logicalSrcIdx = 144;
                    section.data(27).dtTransOffset = 194;

                    ;% rtDW.md1fsm3br3
                    section.data(28).logicalSrcIdx = 145;
                    section.data(28).dtTransOffset = 210;

                    ;% rtDW.be05daasmg
                    section.data(29).logicalSrcIdx = 146;
                    section.data(29).dtTransOffset = 211;

                    ;% rtDW.nq0rryljq1
                    section.data(30).logicalSrcIdx = 147;
                    section.data(30).dtTransOffset = 212;

                    ;% rtDW.ddr4l0n5i3
                    section.data(31).logicalSrcIdx = 148;
                    section.data(31).dtTransOffset = 214;

                    ;% rtDW.by2jasgm4o
                    section.data(32).logicalSrcIdx = 149;
                    section.data(32).dtTransOffset = 215;

                    ;% rtDW.daljbq5gtz
                    section.data(33).logicalSrcIdx = 150;
                    section.data(33).dtTransOffset = 216;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% rtDW.l1l2gip32s.Tail
                    section.data(1).logicalSrcIdx = 151;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.lynamxwk0r.Tail
                    section.data(2).logicalSrcIdx = 152;
                    section.data(2).dtTransOffset = 65;

                    ;% rtDW.nt5ueu32fc
                    section.data(3).logicalSrcIdx = 153;
                    section.data(3).dtTransOffset = 130;

                    ;% rtDW.ihk13omcli
                    section.data(4).logicalSrcIdx = 154;
                    section.data(4).dtTransOffset = 131;

                    ;% rtDW.iwurle5qux
                    section.data(5).logicalSrcIdx = 155;
                    section.data(5).dtTransOffset = 137;

                    ;% rtDW.pe511og3ku
                    section.data(6).logicalSrcIdx = 156;
                    section.data(6).dtTransOffset = 143;

                    ;% rtDW.ldrxgujyb0
                    section.data(7).logicalSrcIdx = 157;
                    section.data(7).dtTransOffset = 149;

                    ;% rtDW.kksik1paup
                    section.data(8).logicalSrcIdx = 158;
                    section.data(8).dtTransOffset = 150;

                    ;% rtDW.cbrsqgmwzt
                    section.data(9).logicalSrcIdx = 159;
                    section.data(9).dtTransOffset = 151;

                    ;% rtDW.j1zkhtxhzf
                    section.data(10).logicalSrcIdx = 160;
                    section.data(10).dtTransOffset = 152;

                    ;% rtDW.lfxnks51wi
                    section.data(11).logicalSrcIdx = 161;
                    section.data(11).dtTransOffset = 153;

                    ;% rtDW.c5hzybmrlt
                    section.data(12).logicalSrcIdx = 162;
                    section.data(12).dtTransOffset = 156;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.cfvgbkovvu
                    section.data(1).logicalSrcIdx = 163;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.anhm4dpp2l
                    section.data(2).logicalSrcIdx = 164;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.iw455stvt1
                    section.data(3).logicalSrcIdx = 165;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.pakc2g42kk
                    section.data(4).logicalSrcIdx = 166;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtDW.oek5idxhme
                    section.data(1).logicalSrcIdx = 167;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bf5ec1ihjs
                    section.data(2).logicalSrcIdx = 168;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.d04ooymyox
                    section.data(3).logicalSrcIdx = 169;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.nmnxbsefd1
                    section.data(4).logicalSrcIdx = 170;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.pny1rb4usr
                    section.data(5).logicalSrcIdx = 171;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.chzc3nt2yy
                    section.data(6).logicalSrcIdx = 172;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtDW.cg1cpca1ek
                    section.data(1).logicalSrcIdx = 173;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.hrnzbhxy5d
                    section.data(2).logicalSrcIdx = 174;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.ikjcop0bgm
                    section.data(3).logicalSrcIdx = 175;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.p2ctlaxtsk
                    section.data(4).logicalSrcIdx = 176;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.bp4ac3vvj5
                    section.data(5).logicalSrcIdx = 177;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.jl5nu1i4l3
                    section.data(6).logicalSrcIdx = 178;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.lh250aajbj
                    section.data(7).logicalSrcIdx = 179;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.edqryqv5bk
                    section.data(8).logicalSrcIdx = 180;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.l3qjgn1jqc
                    section.data(9).logicalSrcIdx = 181;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.cyto13o4kt
                    section.data(10).logicalSrcIdx = 182;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.jgpyhmovpk
                    section.data(11).logicalSrcIdx = 183;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.mu4revjjwi
                    section.data(12).logicalSrcIdx = 184;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.pdvyjvvslc
                    section.data(13).logicalSrcIdx = 185;
                    section.data(13).dtTransOffset = 12;

                    ;% rtDW.kbyn225ku2
                    section.data(14).logicalSrcIdx = 186;
                    section.data(14).dtTransOffset = 13;

                    ;% rtDW.o5u4b02npb
                    section.data(15).logicalSrcIdx = 187;
                    section.data(15).dtTransOffset = 14;

                    ;% rtDW.jcdq2ohx3t
                    section.data(16).logicalSrcIdx = 188;
                    section.data(16).dtTransOffset = 15;

                    ;% rtDW.bwa1fip2ky
                    section.data(17).logicalSrcIdx = 189;
                    section.data(17).dtTransOffset = 16;

                    ;% rtDW.pi3jxhaf2b
                    section.data(18).logicalSrcIdx = 190;
                    section.data(18).dtTransOffset = 17;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hztlwupntw.apnlfrnpo3
                    section.data(1).logicalSrcIdx = 191;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hztlwupntw.ovvez5xelu
                    section.data(1).logicalSrcIdx = 192;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hztlwupntw.dtz1ggkdpo
                    section.data(1).logicalSrcIdx = 193;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.n1ybyykngv.apnlfrnpo3
                    section.data(1).logicalSrcIdx = 194;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.n1ybyykngv.ovvez5xelu
                    section.data(1).logicalSrcIdx = 195;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.n1ybyykngv.dtz1ggkdpo
                    section.data(1).logicalSrcIdx = 196;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.jek5zaxern.datl4fzkmc
                    section.data(1).logicalSrcIdx = 197;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.jek5zaxern.op350srgbo
                    section.data(1).logicalSrcIdx = 198;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.jek5zaxern.eiaswshrvs
                    section.data(1).logicalSrcIdx = 199;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.nikuyjvr0y.datl4fzkmc
                    section.data(1).logicalSrcIdx = 200;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.nikuyjvr0y.op350srgbo
                    section.data(1).logicalSrcIdx = 201;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.nikuyjvr0y.eiaswshrvs
                    section.data(1).logicalSrcIdx = 202;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.enohy5yaap.datl4fzkmc
                    section.data(1).logicalSrcIdx = 203;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.enohy5yaap.op350srgbo
                    section.data(1).logicalSrcIdx = 204;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(22) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.enohy5yaap.eiaswshrvs
                    section.data(1).logicalSrcIdx = 205;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(23) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.pookhwl2ri.aquds3y3qy
                    section.data(1).logicalSrcIdx = 206;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(24) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.pookhwl2ri.b4sgpwle2l
                    section.data(1).logicalSrcIdx = 207;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(25) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.pookhwl2ri.bfcbslmbdi
                    section.data(1).logicalSrcIdx = 208;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(26) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hl5ibqcu3w.aquds3y3qy
                    section.data(1).logicalSrcIdx = 209;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(27) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hl5ibqcu3w.b4sgpwle2l
                    section.data(1).logicalSrcIdx = 210;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(28) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.hl5ibqcu3w.bfcbslmbdi
                    section.data(1).logicalSrcIdx = 211;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(29) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.dffuptpbcz.i2hnwisoi1
                    section.data(1).logicalSrcIdx = 212;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(30) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.dffuptpbcz.fkmv4gfkl0
                    section.data(1).logicalSrcIdx = 213;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(31) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.dffuptpbcz.e3ed3ljbyn
                    section.data(1).logicalSrcIdx = 214;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(32) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bd32gk0ocy.i2hnwisoi1
                    section.data(1).logicalSrcIdx = 215;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(33) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bd32gk0ocy.fkmv4gfkl0
                    section.data(1).logicalSrcIdx = 216;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(34) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.bd32gk0ocy.e3ed3ljbyn
                    section.data(1).logicalSrcIdx = 217;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(35) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.leuhdrxpbe.ckwkdnls5w
                    section.data(1).logicalSrcIdx = 218;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(36) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.leuhdrxpbe.aqynsdznmr
                    section.data(1).logicalSrcIdx = 219;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(37) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.leuhdrxpbe.onahgr5syd
                    section.data(1).logicalSrcIdx = 220;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(38) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.csf3emrtxr.ckwkdnls5w
                    section.data(1).logicalSrcIdx = 221;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(39) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.csf3emrtxr.aqynsdznmr
                    section.data(1).logicalSrcIdx = 222;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(40) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.csf3emrtxr.onahgr5syd
                    section.data(1).logicalSrcIdx = 223;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(41) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.jvaexa3o5a.ckwkdnls5w
                    section.data(1).logicalSrcIdx = 224;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(42) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.jvaexa3o5a.aqynsdznmr
                    section.data(1).logicalSrcIdx = 225;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(43) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.jvaexa3o5a.onahgr5syd
                    section.data(1).logicalSrcIdx = 226;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(44) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.adqmzv0sx0[11].adrjjytrwd
                    section.data(1).logicalSrcIdx = 227;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.adqmzv0sx0[11].mirazmrnvl
                    section.data(2).logicalSrcIdx = 228;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.adqmzv0sx0[11].mczobgpj2t
                    section.data(3).logicalSrcIdx = 229;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(45) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.adqmzv0sx0[11].kd3fwxo3ke
                    section.data(1).logicalSrcIdx = 230;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(46) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.pcwoeb21pm.gxcgpda4hi
                    section.data(1).logicalSrcIdx = 231;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(47) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.pcwoeb21pm.jifjbgbgqy
                    section.data(1).logicalSrcIdx = 232;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(48) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.fthork0k0x2.gxcgpda4hi
                    section.data(1).logicalSrcIdx = 233;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(49) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.fthork0k0x2.jifjbgbgqy
                    section.data(1).logicalSrcIdx = 234;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(50) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 4207121147;
    targMap.checksum1 = 2496750584;
    targMap.checksum2 = 3458008039;
    targMap.checksum3 = 3961977088;


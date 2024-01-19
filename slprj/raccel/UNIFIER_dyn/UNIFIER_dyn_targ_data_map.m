    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 21;
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

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtP.I
                    section.data(1).logicalSrcIdx = 7;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.S
                    section.data(2).logicalSrcIdx = 8;
                    section.data(2).dtTransOffset = 9;

                    ;% rtP.m
                    section.data(3).logicalSrcIdx = 9;
                    section.data(3).dtTransOffset = 10;

                    ;% rtP.xyz_DEP
                    section.data(4).logicalSrcIdx = 10;
                    section.data(4).dtTransOffset = 11;

                    ;% rtP.xyz_cg
                    section.data(5).logicalSrcIdx = 11;
                    section.data(5).dtTransOffset = 47;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtP.vtail_nodes
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.wing_nodes
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 48;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 55;
            section.data(55)  = dumData; %prealloc

                    ;% rtP.Gain1_Gain
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Gain2_Gain
                    section.data(2).logicalSrcIdx = 15;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.Constant_Value
                    section.data(3).logicalSrcIdx = 16;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.zeta_Value
                    section.data(4).logicalSrcIdx = 17;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.testinput_Value
                    section.data(5).logicalSrcIdx = 18;
                    section.data(5).dtTransOffset = 15;

                    ;% rtP.SeaLevelTemperature_Value
                    section.data(6).logicalSrcIdx = 19;
                    section.data(6).dtTransOffset = 34;

                    ;% rtP.Limitaltitudetotroposhere_UpperSat
                    section.data(7).logicalSrcIdx = 20;
                    section.data(7).dtTransOffset = 35;

                    ;% rtP.Limitaltitudetotroposhere_LowerSat
                    section.data(8).logicalSrcIdx = 21;
                    section.data(8).dtTransOffset = 36;

                    ;% rtP.LapseRate_Gain
                    section.data(9).logicalSrcIdx = 22;
                    section.data(9).dtTransOffset = 37;

                    ;% rtP.uT0_Gain
                    section.data(10).logicalSrcIdx = 23;
                    section.data(10).dtTransOffset = 38;

                    ;% rtP.Constant_Value_mlc0xem4a2
                    section.data(11).logicalSrcIdx = 24;
                    section.data(11).dtTransOffset = 39;

                    ;% rtP.AltitudeofTroposphere_Value
                    section.data(12).logicalSrcIdx = 25;
                    section.data(12).dtTransOffset = 40;

                    ;% rtP.LimitaltitudetoStratosphere_UpperSat
                    section.data(13).logicalSrcIdx = 26;
                    section.data(13).dtTransOffset = 41;

                    ;% rtP.LimitaltitudetoStratosphere_LowerSat
                    section.data(14).logicalSrcIdx = 27;
                    section.data(14).dtTransOffset = 42;

                    ;% rtP.gR_Gain
                    section.data(15).logicalSrcIdx = 28;
                    section.data(15).dtTransOffset = 43;

                    ;% rtP.rho0_Gain
                    section.data(16).logicalSrcIdx = 29;
                    section.data(16).dtTransOffset = 44;

                    ;% rtP.Constant1_Value
                    section.data(17).logicalSrcIdx = 30;
                    section.data(17).dtTransOffset = 45;

                    ;% rtP.Constant_Value_ll1hqpke5l
                    section.data(18).logicalSrcIdx = 31;
                    section.data(18).dtTransOffset = 46;

                    ;% rtP.Constant_Value_exkenlsy3u
                    section.data(19).logicalSrcIdx = 32;
                    section.data(19).dtTransOffset = 47;

                    ;% rtP.Constant_Value_izgjegg0j4
                    section.data(20).logicalSrcIdx = 33;
                    section.data(20).dtTransOffset = 50;

                    ;% rtP.Constant1_Value_meik51c4df
                    section.data(21).logicalSrcIdx = 34;
                    section.data(21).dtTransOffset = 58;

                    ;% rtP.Saturation_UpperSat
                    section.data(22).logicalSrcIdx = 35;
                    section.data(22).dtTransOffset = 66;

                    ;% rtP.Saturation_LowerSat
                    section.data(23).logicalSrcIdx = 36;
                    section.data(23).dtTransOffset = 67;

                    ;% rtP.Saturation1_UpperSat
                    section.data(24).logicalSrcIdx = 37;
                    section.data(24).dtTransOffset = 68;

                    ;% rtP.Saturation1_LowerSat
                    section.data(25).logicalSrcIdx = 38;
                    section.data(25).dtTransOffset = 69;

                    ;% rtP.Saturation2_UpperSat
                    section.data(26).logicalSrcIdx = 39;
                    section.data(26).dtTransOffset = 70;

                    ;% rtP.Saturation2_LowerSat
                    section.data(27).logicalSrcIdx = 40;
                    section.data(27).dtTransOffset = 71;

                    ;% rtP.Saturation3_UpperSat
                    section.data(28).logicalSrcIdx = 41;
                    section.data(28).dtTransOffset = 72;

                    ;% rtP.Saturation3_LowerSat
                    section.data(29).logicalSrcIdx = 42;
                    section.data(29).dtTransOffset = 73;

                    ;% rtP.Saturation6_UpperSat
                    section.data(30).logicalSrcIdx = 43;
                    section.data(30).dtTransOffset = 74;

                    ;% rtP.Saturation6_LowerSat
                    section.data(31).logicalSrcIdx = 44;
                    section.data(31).dtTransOffset = 75;

                    ;% rtP.Saturation4_UpperSat
                    section.data(32).logicalSrcIdx = 45;
                    section.data(32).dtTransOffset = 76;

                    ;% rtP.Saturation4_LowerSat
                    section.data(33).logicalSrcIdx = 46;
                    section.data(33).dtTransOffset = 77;

                    ;% rtP.Constant8_Value
                    section.data(34).logicalSrcIdx = 47;
                    section.data(34).dtTransOffset = 78;

                    ;% rtP.Constant_Value_kx5dv3qh2a
                    section.data(35).logicalSrcIdx = 48;
                    section.data(35).dtTransOffset = 94;

                    ;% rtP.Constant1_Value_dxjow4r24m
                    section.data(36).logicalSrcIdx = 49;
                    section.data(36).dtTransOffset = 102;

                    ;% rtP.Constant8_Value_cr0us2qlbv
                    section.data(37).logicalSrcIdx = 50;
                    section.data(37).dtTransOffset = 110;

                    ;% rtP.Constant_Value_lkalxliguo
                    section.data(38).logicalSrcIdx = 51;
                    section.data(38).dtTransOffset = 126;

                    ;% rtP.Constant8_Value_dj5ncyqbcf
                    section.data(39).logicalSrcIdx = 52;
                    section.data(39).dtTransOffset = 147;

                    ;% rtP.Constant8_Value_hy4ct0z05y
                    section.data(40).logicalSrcIdx = 53;
                    section.data(40).dtTransOffset = 152;

                    ;% rtP.Constant_Value_bchqth404u
                    section.data(41).logicalSrcIdx = 54;
                    section.data(41).dtTransOffset = 154;

                    ;% rtP.Constant8_Value_kwpfdqsyq1
                    section.data(42).logicalSrcIdx = 55;
                    section.data(42).dtTransOffset = 175;

                    ;% rtP.Constant8_Value_m3ahup3xji
                    section.data(43).logicalSrcIdx = 56;
                    section.data(43).dtTransOffset = 180;

                    ;% rtP.Constant_Value_ec1rbuxqhz
                    section.data(44).logicalSrcIdx = 57;
                    section.data(44).dtTransOffset = 182;

                    ;% rtP.Gain_Gain
                    section.data(45).logicalSrcIdx = 58;
                    section.data(45).dtTransOffset = 183;

                    ;% rtP.Constant2_Value
                    section.data(46).logicalSrcIdx = 59;
                    section.data(46).dtTransOffset = 184;

                    ;% rtP.Gain_Gain_jhzuipt41u
                    section.data(47).logicalSrcIdx = 60;
                    section.data(47).dtTransOffset = 193;

                    ;% rtP.Constant2_Value_lirfr5mubp
                    section.data(48).logicalSrcIdx = 61;
                    section.data(48).dtTransOffset = 205;

                    ;% rtP.Inclination_Value
                    section.data(49).logicalSrcIdx = 62;
                    section.data(49).dtTransOffset = 217;

                    ;% rtP.Constant_Value_kr4kbsbfsk
                    section.data(50).logicalSrcIdx = 63;
                    section.data(50).dtTransOffset = 218;

                    ;% rtP.Multiply_Gain
                    section.data(51).logicalSrcIdx = 64;
                    section.data(51).dtTransOffset = 219;

                    ;% rtP.uDLookupTable1_tableData
                    section.data(52).logicalSrcIdx = 65;
                    section.data(52).dtTransOffset = 220;

                    ;% rtP.uDLookupTable1_bp01Data
                    section.data(53).logicalSrcIdx = 66;
                    section.data(53).dtTransOffset = 222;

                    ;% rtP.Constant_Value_dtyrktojcw
                    section.data(54).logicalSrcIdx = 67;
                    section.data(54).dtTransOffset = 224;

                    ;% rtP.Gain_Gain_gmzj2h1bwx
                    section.data(55).logicalSrcIdx = 68;
                    section.data(55).dtTransOffset = 225;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 19;
            section.data(19)  = dumData; %prealloc

                    ;% rtP.Gain_Gain_ovou53gniu
                    section.data(1).logicalSrcIdx = 69;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.Gain_Gain_mvu5sy12vu
                    section.data(2).logicalSrcIdx = 70;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.uDLookupTable_bp01Data
                    section.data(3).logicalSrcIdx = 71;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.uDLookupTable1_bp01Data_o3lj0rj2gn
                    section.data(4).logicalSrcIdx = 72;
                    section.data(4).dtTransOffset = 8;

                    ;% rtP.uDLookupTable2_bp01Data
                    section.data(5).logicalSrcIdx = 73;
                    section.data(5).dtTransOffset = 14;

                    ;% rtP.Gain2_Gain_a2ertcz4ne
                    section.data(6).logicalSrcIdx = 74;
                    section.data(6).dtTransOffset = 20;

                    ;% rtP.Gain3_Gain
                    section.data(7).logicalSrcIdx = 75;
                    section.data(7).dtTransOffset = 21;

                    ;% rtP.Prelookup_BreakpointsData
                    section.data(8).logicalSrcIdx = 76;
                    section.data(8).dtTransOffset = 22;

                    ;% rtP.Prelookup1_BreakpointsData
                    section.data(9).logicalSrcIdx = 77;
                    section.data(9).dtTransOffset = 35;

                    ;% rtP.Constant_Value_dggd0yls2s
                    section.data(10).logicalSrcIdx = 78;
                    section.data(10).dtTransOffset = 50;

                    ;% rtP.Gain_Gain_ngpzxxezsf
                    section.data(11).logicalSrcIdx = 79;
                    section.data(11).dtTransOffset = 51;

                    ;% rtP.Constant7_Value
                    section.data(12).logicalSrcIdx = 80;
                    section.data(12).dtTransOffset = 52;

                    ;% rtP.Constant1_Value_jtw2pfsmen
                    section.data(13).logicalSrcIdx = 81;
                    section.data(13).dtTransOffset = 68;

                    ;% rtP.NodePoints_Value
                    section.data(14).logicalSrcIdx = 82;
                    section.data(14).dtTransOffset = 116;

                    ;% rtP.NodePoints_Value_iel3jxerxr
                    section.data(15).logicalSrcIdx = 83;
                    section.data(15).dtTransOffset = 137;

                    ;% rtP.Constant1_Value_fodj5rxow1
                    section.data(16).logicalSrcIdx = 84;
                    section.data(16).dtTransOffset = 158;

                    ;% rtP.extra_drag_Value
                    section.data(17).logicalSrcIdx = 85;
                    section.data(17).dtTransOffset = 159;

                    ;% rtP.gear_drag_Value
                    section.data(18).logicalSrcIdx = 86;
                    section.data(18).dtTransOffset = 160;

                    ;% rtP.Gain_Gain_jabdopn2nb
                    section.data(19).logicalSrcIdx = 87;
                    section.data(19).dtTransOffset = 161;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 57;
            section.data(57)  = dumData; %prealloc

                    ;% rtP.InterpolationUsingPrelookup1_dimSize
                    section.data(1).logicalSrcIdx = 88;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex
                    section.data(2).logicalSrcIdx = 89;
                    section.data(2).dtTransOffset = 4;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_goowtl1isu
                    section.data(3).logicalSrcIdx = 90;
                    section.data(3).dtTransOffset = 8;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex_gcrts0kvey
                    section.data(4).logicalSrcIdx = 91;
                    section.data(4).dtTransOffset = 12;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize
                    section.data(5).logicalSrcIdx = 92;
                    section.data(5).dtTransOffset = 16;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex
                    section.data(6).logicalSrcIdx = 93;
                    section.data(6).dtTransOffset = 20;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_hjcwwxhrb2
                    section.data(7).logicalSrcIdx = 94;
                    section.data(7).dtTransOffset = 24;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex_hmktoionv2
                    section.data(8).logicalSrcIdx = 95;
                    section.data(8).dtTransOffset = 28;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize
                    section.data(9).logicalSrcIdx = 96;
                    section.data(9).dtTransOffset = 32;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex
                    section.data(10).logicalSrcIdx = 97;
                    section.data(10).dtTransOffset = 36;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_eey1a1evp1
                    section.data(11).logicalSrcIdx = 98;
                    section.data(11).dtTransOffset = 40;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex_inqyzx0bkv
                    section.data(12).logicalSrcIdx = 99;
                    section.data(12).dtTransOffset = 44;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_jgranlzjdr
                    section.data(13).logicalSrcIdx = 100;
                    section.data(13).dtTransOffset = 48;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex_m1elfxqfrm
                    section.data(14).logicalSrcIdx = 101;
                    section.data(14).dtTransOffset = 52;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_hgrobm0ojs
                    section.data(15).logicalSrcIdx = 102;
                    section.data(15).dtTransOffset = 56;

                    ;% rtP.InterpolationUsingPrelookup1_maxIndex_kj53253sjw
                    section.data(16).logicalSrcIdx = 103;
                    section.data(16).dtTransOffset = 60;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_e5mnlcnsgz
                    section.data(17).logicalSrcIdx = 104;
                    section.data(17).dtTransOffset = 64;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex_ic1jmobgnb
                    section.data(18).logicalSrcIdx = 105;
                    section.data(18).dtTransOffset = 68;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_fv3gcuk1rh
                    section.data(19).logicalSrcIdx = 106;
                    section.data(19).dtTransOffset = 72;

                    ;% rtP.InterpolationUsingPrelookup2_maxIndex_joswbgit4t
                    section.data(20).logicalSrcIdx = 107;
                    section.data(20).dtTransOffset = 76;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_gotbz31jut
                    section.data(21).logicalSrcIdx = 108;
                    section.data(21).dtTransOffset = 80;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex_iyvebvf0hr
                    section.data(22).logicalSrcIdx = 109;
                    section.data(22).dtTransOffset = 84;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_i1e0soyo1i
                    section.data(23).logicalSrcIdx = 110;
                    section.data(23).dtTransOffset = 88;

                    ;% rtP.InterpolationUsingPrelookup3_maxIndex_axhtziqjmb
                    section.data(24).logicalSrcIdx = 111;
                    section.data(24).dtTransOffset = 92;

                    ;% rtP.V_induced_dimSize
                    section.data(25).logicalSrcIdx = 112;
                    section.data(25).dtTransOffset = 96;

                    ;% rtP.alpha_induced_dimSize
                    section.data(26).logicalSrcIdx = 113;
                    section.data(26).dtTransOffset = 100;

                    ;% rtP.InterpolationUsingPrelookup1_dimSize_kbujhpqt4p
                    section.data(27).logicalSrcIdx = 114;
                    section.data(27).dtTransOffset = 104;

                    ;% rtP.InterpolationUsingPrelookup2_dimSize_it0njeibeo
                    section.data(28).logicalSrcIdx = 115;
                    section.data(28).dtTransOffset = 107;

                    ;% rtP.InterpolationUsingPrelookup3_dimSize_h5lelt5fk5
                    section.data(29).logicalSrcIdx = 116;
                    section.data(29).dtTransOffset = 110;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize
                    section.data(30).logicalSrcIdx = 117;
                    section.data(30).dtTransOffset = 113;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex
                    section.data(31).logicalSrcIdx = 118;
                    section.data(31).dtTransOffset = 117;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_eonzf4khoz
                    section.data(32).logicalSrcIdx = 119;
                    section.data(32).dtTransOffset = 121;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex_ldg1ql3t42
                    section.data(33).logicalSrcIdx = 120;
                    section.data(33).dtTransOffset = 125;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize
                    section.data(34).logicalSrcIdx = 121;
                    section.data(34).dtTransOffset = 129;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex
                    section.data(35).logicalSrcIdx = 122;
                    section.data(35).dtTransOffset = 133;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_m1b3rqhw3t
                    section.data(36).logicalSrcIdx = 123;
                    section.data(36).dtTransOffset = 137;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex_l0p20lh4bw
                    section.data(37).logicalSrcIdx = 124;
                    section.data(37).dtTransOffset = 141;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize
                    section.data(38).logicalSrcIdx = 125;
                    section.data(38).dtTransOffset = 145;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex
                    section.data(39).logicalSrcIdx = 126;
                    section.data(39).dtTransOffset = 149;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_ewytp2yzsl
                    section.data(40).logicalSrcIdx = 127;
                    section.data(40).dtTransOffset = 153;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex_fa5a0eaqeu
                    section.data(41).logicalSrcIdx = 128;
                    section.data(41).dtTransOffset = 157;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_frefplnidc
                    section.data(42).logicalSrcIdx = 129;
                    section.data(42).dtTransOffset = 161;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex_onrk5innhu
                    section.data(43).logicalSrcIdx = 130;
                    section.data(43).dtTransOffset = 165;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_kh3x5zfkli
                    section.data(44).logicalSrcIdx = 131;
                    section.data(44).dtTransOffset = 169;

                    ;% rtP.InterpolationUsingPrelookup4_maxIndex_leuk5avc1v
                    section.data(45).logicalSrcIdx = 132;
                    section.data(45).dtTransOffset = 173;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_licoblhfnw
                    section.data(46).logicalSrcIdx = 133;
                    section.data(46).dtTransOffset = 177;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex_eshiygopfu
                    section.data(47).logicalSrcIdx = 134;
                    section.data(47).dtTransOffset = 181;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_kcrhpwfjfn
                    section.data(48).logicalSrcIdx = 135;
                    section.data(48).dtTransOffset = 185;

                    ;% rtP.InterpolationUsingPrelookup5_maxIndex_brkchxcoij
                    section.data(49).logicalSrcIdx = 136;
                    section.data(49).dtTransOffset = 189;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_gllaksp5ia
                    section.data(50).logicalSrcIdx = 137;
                    section.data(50).dtTransOffset = 193;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex_ny0js42i4o
                    section.data(51).logicalSrcIdx = 138;
                    section.data(51).dtTransOffset = 197;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_npg5h2ocwn
                    section.data(52).logicalSrcIdx = 139;
                    section.data(52).dtTransOffset = 201;

                    ;% rtP.InterpolationUsingPrelookup6_maxIndex_lpfi2gwlwq
                    section.data(53).logicalSrcIdx = 140;
                    section.data(53).dtTransOffset = 205;

                    ;% rtP.InterpolationUsingPrelookup4_dimSize_lnthg1rnjp
                    section.data(54).logicalSrcIdx = 141;
                    section.data(54).dtTransOffset = 209;

                    ;% rtP.InterpolationUsingPrelookup5_dimSize_brj4qiei0w
                    section.data(55).logicalSrcIdx = 142;
                    section.data(55).dtTransOffset = 212;

                    ;% rtP.InterpolationUsingPrelookup6_dimSize_nqfnlt53ag
                    section.data(56).logicalSrcIdx = 143;
                    section.data(56).dtTransOffset = 215;

                    ;% rtP.Plookup_maxIndex
                    section.data(57).logicalSrcIdx = 144;
                    section.data(57).dtTransOffset = 218;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 25;
            section.data(25)  = dumData; %prealloc

                    ;% rtP.au023bergz.actf2T_Gain
                    section.data(1).logicalSrcIdx = 145;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.au023bergz.Saturation2_UpperSat
                    section.data(2).logicalSrcIdx = 146;
                    section.data(2).dtTransOffset = 1;

                    ;% rtP.au023bergz.Saturation2_LowerSat
                    section.data(3).logicalSrcIdx = 147;
                    section.data(3).dtTransOffset = 2;

                    ;% rtP.au023bergz.Switch1_Threshold
                    section.data(4).logicalSrcIdx = 148;
                    section.data(4).dtTransOffset = 3;

                    ;% rtP.au023bergz.Gain1_Gain
                    section.data(5).logicalSrcIdx = 149;
                    section.data(5).dtTransOffset = 4;

                    ;% rtP.au023bergz.Saturation_UpperSat
                    section.data(6).logicalSrcIdx = 150;
                    section.data(6).dtTransOffset = 5;

                    ;% rtP.au023bergz.Saturation_LowerSat
                    section.data(7).logicalSrcIdx = 151;
                    section.data(7).dtTransOffset = 6;

                    ;% rtP.au023bergz.Gain2_Gain
                    section.data(8).logicalSrcIdx = 152;
                    section.data(8).dtTransOffset = 7;

                    ;% rtP.au023bergz.Saturation1_UpperSat
                    section.data(9).logicalSrcIdx = 153;
                    section.data(9).dtTransOffset = 8;

                    ;% rtP.au023bergz.Saturation1_LowerSat
                    section.data(10).logicalSrcIdx = 154;
                    section.data(10).dtTransOffset = 9;

                    ;% rtP.au023bergz.Gain_Gain
                    section.data(11).logicalSrcIdx = 155;
                    section.data(11).dtTransOffset = 10;

                    ;% rtP.au023bergz.Saturation1_UpperSat_o3uhb5q0dz
                    section.data(12).logicalSrcIdx = 156;
                    section.data(12).dtTransOffset = 11;

                    ;% rtP.au023bergz.Saturation1_LowerSat_cob1qvjvl1
                    section.data(13).logicalSrcIdx = 157;
                    section.data(13).dtTransOffset = 12;

                    ;% rtP.au023bergz.Gain3_Gain
                    section.data(14).logicalSrcIdx = 158;
                    section.data(14).dtTransOffset = 13;

                    ;% rtP.au023bergz.Saturation_UpperSat_dzx4r24qqm
                    section.data(15).logicalSrcIdx = 159;
                    section.data(15).dtTransOffset = 14;

                    ;% rtP.au023bergz.Saturation_LowerSat_lu14kynpbe
                    section.data(16).logicalSrcIdx = 160;
                    section.data(16).dtTransOffset = 15;

                    ;% rtP.au023bergz.Gain3_Gain_kiqvbbswpr
                    section.data(17).logicalSrcIdx = 161;
                    section.data(17).dtTransOffset = 16;

                    ;% rtP.au023bergz.Gain5_Gain
                    section.data(18).logicalSrcIdx = 162;
                    section.data(18).dtTransOffset = 17;

                    ;% rtP.au023bergz.Saturation3_UpperSat
                    section.data(19).logicalSrcIdx = 163;
                    section.data(19).dtTransOffset = 18;

                    ;% rtP.au023bergz.Saturation3_LowerSat
                    section.data(20).logicalSrcIdx = 164;
                    section.data(20).dtTransOffset = 19;

                    ;% rtP.au023bergz.Constant3_Value
                    section.data(21).logicalSrcIdx = 165;
                    section.data(21).dtTransOffset = 20;

                    ;% rtP.au023bergz.Constant_Value
                    section.data(22).logicalSrcIdx = 166;
                    section.data(22).dtTransOffset = 21;

                    ;% rtP.au023bergz.Constant1_Value
                    section.data(23).logicalSrcIdx = 167;
                    section.data(23).dtTransOffset = 22;

                    ;% rtP.au023bergz.DEP_incidence_Value
                    section.data(24).logicalSrcIdx = 168;
                    section.data(24).dtTransOffset = 23;

                    ;% rtP.au023bergz.Constant_Value_e5dci5j5wh
                    section.data(25).logicalSrcIdx = 169;
                    section.data(25).dtTransOffset = 24;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.au023bergz.T2rpm_maxIndex
                    section.data(1).logicalSrcIdx = 170;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.oeyei2gsmn.Constant_Value
                    section.data(1).logicalSrcIdx = 171;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.oeyei2gsmn.Constant_Value_lhjgiuieqz
                    section.data(1).logicalSrcIdx = 172;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.jz0qdcsmmmwh5r.Constant_Value
                    section.data(1).logicalSrcIdx = 173;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.jz0qdcsmmmwh5r.Constant_Value_bcqheaf40z
                    section.data(1).logicalSrcIdx = 174;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.jz0qdcsmmmw.Constant1_Value
                    section.data(1).logicalSrcIdx = 175;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.jz0qdcsmmm.Constant1_Value
                    section.data(1).logicalSrcIdx = 176;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.p5rpnypkdo.K_slope_Gain
                    section.data(1).logicalSrcIdx = 177;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(21) = section;
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
        nTotSects     = 11;
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
            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% rtB.noeiauttpl
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.jefg5cifsj
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3;

                    ;% rtB.l3mgpdtrrg
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% rtB.kunmel5bx4
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 7;

                    ;% rtB.mgyjrcfqfu
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 23;

                    ;% rtB.cyv21phhbm
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 39;

                    ;% rtB.czxnr0doyy
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 42;

                    ;% rtB.kqrxmtokjd
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 45;

                    ;% rtB.bjhstbmrsn
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 54;

                    ;% rtB.osqwflveuv
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 55;

                    ;% rtB.bp0afaxpp5
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 56;

                    ;% rtB.j1stuyzs1t
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 57;

                    ;% rtB.hzhdx3sz5v
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 60;

                    ;% rtB.fp54rsi3hk
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 63;

                    ;% rtB.omkpqlajlz
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 75;

                    ;% rtB.gfknqoynom
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 78;

                    ;% rtB.orlelyhfjl
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 79;

                    ;% rtB.p1lfhtknc0
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 80;

                    ;% rtB.nluycx3bh3
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 92;

                    ;% rtB.jltpjpl4zp
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 104;

                    ;% rtB.etlvxwxtcy
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 140;

                    ;% rtB.fqp13muoyo
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 152;

                    ;% rtB.bftm5ocvno
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 188;

                    ;% rtB.eljuwfhp1f
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 200;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% rtB.nhcvscc4t0
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.pmh50qaazg
                    section.data(2).logicalSrcIdx = 25;
                    section.data(2).dtTransOffset = 16;

                    ;% rtB.g53iqbai0i
                    section.data(3).logicalSrcIdx = 26;
                    section.data(3).dtTransOffset = 32;

                    ;% rtB.jqfgyi5cqv
                    section.data(4).logicalSrcIdx = 27;
                    section.data(4).dtTransOffset = 33;

                    ;% rtB.bqft1jkk0z
                    section.data(5).logicalSrcIdx = 28;
                    section.data(5).dtTransOffset = 34;

                    ;% rtB.fu5nkfrvvl
                    section.data(6).logicalSrcIdx = 29;
                    section.data(6).dtTransOffset = 35;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 24;
            section.data(24)  = dumData; %prealloc

                    ;% rtB.on23viyejw
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.pqjyj5rgda
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 7;

                    ;% rtB.fpov3sjl4o
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 28;

                    ;% rtB.bdrmalqcon
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 49;

                    ;% rtB.jdsvzdisey
                    section.data(5).logicalSrcIdx = 34;
                    section.data(5).dtTransOffset = 97;

                    ;% rtB.lxkh42xndm
                    section.data(6).logicalSrcIdx = 35;
                    section.data(6).dtTransOffset = 100;

                    ;% rtB.lcnor15erx
                    section.data(7).logicalSrcIdx = 36;
                    section.data(7).dtTransOffset = 103;

                    ;% rtB.ecjaklyjaq
                    section.data(8).logicalSrcIdx = 37;
                    section.data(8).dtTransOffset = 106;

                    ;% rtB.f5f1ypai11
                    section.data(9).logicalSrcIdx = 38;
                    section.data(9).dtTransOffset = 107;

                    ;% rtB.ayw0otszrq
                    section.data(10).logicalSrcIdx = 39;
                    section.data(10).dtTransOffset = 110;

                    ;% rtB.lkci5wisjr
                    section.data(11).logicalSrcIdx = 40;
                    section.data(11).dtTransOffset = 111;

                    ;% rtB.gbccn4rvbj
                    section.data(12).logicalSrcIdx = 41;
                    section.data(12).dtTransOffset = 112;

                    ;% rtB.igwg4uissg
                    section.data(13).logicalSrcIdx = 42;
                    section.data(13).dtTransOffset = 113;

                    ;% rtB.ejdl4n31el
                    section.data(14).logicalSrcIdx = 43;
                    section.data(14).dtTransOffset = 114;

                    ;% rtB.bavqi0oauu
                    section.data(15).logicalSrcIdx = 44;
                    section.data(15).dtTransOffset = 117;

                    ;% rtB.kainbdj3jz
                    section.data(16).logicalSrcIdx = 45;
                    section.data(16).dtTransOffset = 138;

                    ;% rtB.bavqi0oauug
                    section.data(17).logicalSrcIdx = 46;
                    section.data(17).dtTransOffset = 159;

                    ;% rtB.kainbdj3jzn
                    section.data(18).logicalSrcIdx = 47;
                    section.data(18).dtTransOffset = 180;

                    ;% rtB.kainbdj3jznl
                    section.data(19).logicalSrcIdx = 48;
                    section.data(19).dtTransOffset = 201;

                    ;% rtB.jet1i0an5d
                    section.data(20).logicalSrcIdx = 49;
                    section.data(20).dtTransOffset = 249;

                    ;% rtB.crx1qgibvo
                    section.data(21).logicalSrcIdx = 50;
                    section.data(21).dtTransOffset = 263;

                    ;% rtB.dzpd4knetl
                    section.data(22).logicalSrcIdx = 51;
                    section.data(22).dtTransOffset = 277;

                    ;% rtB.jet1i0an5do
                    section.data(23).logicalSrcIdx = 52;
                    section.data(23).dtTransOffset = 293;

                    ;% rtB.crx1qgibvon
                    section.data(24).logicalSrcIdx = 53;
                    section.data(24).dtTransOffset = 309;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.au023bergz[11].aqav5cdmuv
                    section.data(1).logicalSrcIdx = 54;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.au023bergz[11].fai5wajm52
                    section.data(1).logicalSrcIdx = 55;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jz0qdcsmmmwh5rk[6].omlkzp34xv
                    section.data(1).logicalSrcIdx = 56;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jz0qdcsmmmwh5[6].m5kvx1lnef
                    section.data(1).logicalSrcIdx = 57;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jz0qdcsmmmwh[15].m05clr3gxy
                    section.data(1).logicalSrcIdx = 58;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jz0qdcsmmmw[13].kz2ejerpof
                    section.data(1).logicalSrcIdx = 59;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.jz0qdcsmmm[15].ijneevr0hx
                    section.data(1).logicalSrcIdx = 60;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.p5rpnypkdo[11].gbstdhmylq
                    section.data(1).logicalSrcIdx = 61;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
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
        nTotSects     = 5;
        sectIdxOffset = 11;

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
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.e3yadhhovi
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.mw5cjkjcde.AQHandles
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.flhwc3z3tt.LoggedData
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.nw45trtl3m.LoggedData
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 32;
            section.data(32)  = dumData; %prealloc

                    ;% rtDW.esnn32lqad
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.lkiofcx0nc
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 5;

                    ;% rtDW.d45t54zzh0
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 10;

                    ;% rtDW.obz0u22bxk
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 15;

                    ;% rtDW.mtbzqory0k
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 17;

                    ;% rtDW.cv4ea1x5bf
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 19;

                    ;% rtDW.p0luwllcwa
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 21;

                    ;% rtDW.momrqi2s1w
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 26;

                    ;% rtDW.jevgaddxph
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 31;

                    ;% rtDW.dctbywbcef
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 36;

                    ;% rtDW.iiazkmp3zq
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 38;

                    ;% rtDW.pb5bsdxxpa
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 40;

                    ;% rtDW.p4va2j4maz
                    section.data(13).logicalSrcIdx = 16;
                    section.data(13).dtTransOffset = 42;

                    ;% rtDW.ldxzligihn
                    section.data(14).logicalSrcIdx = 17;
                    section.data(14).dtTransOffset = 58;

                    ;% rtDW.fb00myaqvg
                    section.data(15).logicalSrcIdx = 18;
                    section.data(15).dtTransOffset = 74;

                    ;% rtDW.hkblkqalfc
                    section.data(16).logicalSrcIdx = 19;
                    section.data(16).dtTransOffset = 90;

                    ;% rtDW.eewvdaqf4r
                    section.data(17).logicalSrcIdx = 20;
                    section.data(17).dtTransOffset = 106;

                    ;% rtDW.dgwkzgwl00
                    section.data(18).logicalSrcIdx = 21;
                    section.data(18).dtTransOffset = 122;

                    ;% rtDW.lsgiesztth
                    section.data(19).logicalSrcIdx = 22;
                    section.data(19).dtTransOffset = 138;

                    ;% rtDW.m05sv2n1iq
                    section.data(20).logicalSrcIdx = 23;
                    section.data(20).dtTransOffset = 154;

                    ;% rtDW.khbxaboxwb
                    section.data(21).logicalSrcIdx = 24;
                    section.data(21).dtTransOffset = 170;

                    ;% rtDW.djzedhv1ik
                    section.data(22).logicalSrcIdx = 25;
                    section.data(22).dtTransOffset = 171;

                    ;% rtDW.luravducvq
                    section.data(23).logicalSrcIdx = 26;
                    section.data(23).dtTransOffset = 172;

                    ;% rtDW.e15temhbyp
                    section.data(24).logicalSrcIdx = 27;
                    section.data(24).dtTransOffset = 188;

                    ;% rtDW.jseguf13yy
                    section.data(25).logicalSrcIdx = 28;
                    section.data(25).dtTransOffset = 204;

                    ;% rtDW.cfngthrtfc
                    section.data(26).logicalSrcIdx = 29;
                    section.data(26).dtTransOffset = 205;

                    ;% rtDW.k3rxirp2ci
                    section.data(27).logicalSrcIdx = 30;
                    section.data(27).dtTransOffset = 206;

                    ;% rtDW.nfqrlmtid3
                    section.data(28).logicalSrcIdx = 31;
                    section.data(28).dtTransOffset = 207;

                    ;% rtDW.oa32expm1m
                    section.data(29).logicalSrcIdx = 32;
                    section.data(29).dtTransOffset = 208;

                    ;% rtDW.fiq4gqvmys
                    section.data(30).logicalSrcIdx = 33;
                    section.data(30).dtTransOffset = 209;

                    ;% rtDW.mnbvnpxi3q
                    section.data(31).logicalSrcIdx = 34;
                    section.data(31).dtTransOffset = 210;

                    ;% rtDW.mitq3fljz5
                    section.data(32).logicalSrcIdx = 35;
                    section.data(32).dtTransOffset = 211;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtDW.lmdux514h1
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.ckg5ciehpx
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.au023bergz[11].hq0naomli3
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.au023bergz[11].g1bez0i0y4
                    section.data(2).logicalSrcIdx = 39;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.au023bergz[11].ojom230ae1
                    section.data(3).logicalSrcIdx = 40;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
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


    targMap.checksum0 = 3469205189;
    targMap.checksum1 = 2159496850;
    targMap.checksum2 = 2886346932;
    targMap.checksum3 = 3540084195;


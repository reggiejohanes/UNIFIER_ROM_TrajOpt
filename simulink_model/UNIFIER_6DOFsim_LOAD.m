
clear all
% close all
% clc

addpath(genpath(pwd))

load UNIFIER_LOAD.mat

% Tracking reference
load UNIFIERLanding_20240524_162938.mat solution Va alpha dFlap
% load UNIFIERLanding_20240613_232402.mat solution Va alpha dFlap rodft % v1
% load UNIFIERLanding_20240613_192010.mat solution Va alpha dFlap rodft % v2
% load UNIFIERLanding_20240613_190735.mat solution Va alpha dFlap rodft % v3

t_sim = solution.tf;



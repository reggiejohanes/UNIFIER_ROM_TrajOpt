% clc
clear all
% close all

Va_ub=75;
Va_lb=35;
alpha=20;

umax=Va_ub;
umin=Va_lb*cosd(alpha);

wmax=Va_ub*sind(alpha);
wmin=-wmax;

Va_max=sqrt(umax^2+wmax^2);
Va_min=sqrt(umin^2+0^2);

alpha_max=atand(wmax/umin);
alpha_min=atand(wmin/umin);
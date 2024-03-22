
clear

z0 = -1219;
z  = -1219:-5;
p  = exp(((z-z0)/z0).^2);

figure
plot(z,p,'-r','LineWidth',1.5)
grid on
xlim([-1400 200])
ylabel('p (Stage cost weight factor)')
xlabel('z, m')
xline(-1219,'-b',{'Cruise altitude'})
xline(-5,'-b',{'Terminal altitude'})

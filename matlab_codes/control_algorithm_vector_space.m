% This code calculates the change in length of each section of the wire 
% The robot contains 4 sections and each section contains 10 continuum links
% All 4 sections can be controlled seperately in 4 different directions
% Hence, total 4*4 = 16 directions of motion are possible
% By calculating change in length for each step of change in angle, we can...
% ...calculate the rotation required at the motor shaft.

close all;
clear all;
clc;

links = 4; 
L0 = 250; %Initial length of all wires 
% L1=200;
% d = 35; %Distance between two opposite wires
h0 = 20; %Gap between two consecutive links
% N1 = 10; % Number of links in section-1
% N2 = 10; % Number of links in section-2
% N3 = 10; % Number of links in section-3
% N4 = 10; % Number of links in section-4
% a = (d/2);
% b = (d/2);l1=0;
l = 25;
p=1;k=1;p1=0;p2=1;
theta_deg=zeros(1,4); 
th1_deg=zeros(1,4);
phy_deg=zeros(1,4); 
phy1_deg=zeros(1,4);
th1=zeros(1,4);
phy1=zeros(1,4));
alpha2 = (15*pi)/180;
alpha3 = (30*pi)/180;
alpha4 = (45.5*pi)/180;
n = 0;
r=0;
count=1;
count2 = 1;
c=0;
x=0;


for i=1:1:4
   u(i,1)=0; %x co-ordinate of base points
   u(i,2)=0; %y co-ordinate of base points
   u(i,3)=n*l; %z co-ordinate of base points
   v(i,1)=l*sin(th1(i)); %vector length in x-dir
   v(i,2)=l*sin(phy1(i)); %vector length in y-dir
   v(i,3)=l*cos(th1(i))*cos(phy1(i)); %vector length in z-dir
   n = n+1;
end
for i=1:1:4
        quiver3(u(i,1),u(i,2),u(i,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
        hold on;
end
hold off;
   
while 1
    y = input('Turn(w/s/a/d) or m to move forward: ','s')
    if (y=='w' || y=='s' || y=='a' || y=='d') % This condition is used to define increamental values of theta
        if y=='w'        
            theta_deg(links) =  th1_deg(links) + 1;
            th1_deg(j) = theta_deg(j);
            th1(j) = th1_deg(j) * (pi/180);                 
        end
        if y=='s'        
            theta_deg(links) = th1_deg(links) - 1;
            th1_deg(links) = theta_deg(links);
            th1(links) = th1_deg(links) * (pi/180);                 
        end
        if y=='a'                
            phy_deg(links) = phy1_deg(links) + 1;
            phy1_deg(links) = phy_deg(links);
            phy1(links) = phy1_deg(links) * (pi/180);             
        end
        if y=='d'              
            phy_deg(j) = phy1_deg(j) - 1;
            phy1_deg(j) = phy_deg(j);
            phy1(j) = phy1_deg(j) * (pi/180);             
        end        
    end              
        
    for i=32:1:40
        u(i,1)=u((i-1),1) + l*sin(i*th1(i)); 
        u(i,2)=u((i-1),2) + l*sin(i*phy1(i));
        u(i,3)=u((i-1),3) + l*cos(i*th1(i))*cos(i*phy1(i));
    end
   
    for i=1:1:(N1+N2+N3+N4)
        quiver3(u(i,1),u(i,2),u(i,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
        hold on;
    end
    hold off;
   
    for i=31:1:40
        v2(i) = sqrt((v(i,1)^2)+(v(i,2)^2)+(v(i,3)^2)); % This will give the array of vector length 
    end

    % Calculation for length of last section is as follows
    for i=31:1:40
        L1(i) = v2(i) - (d/2)*sin(th1(i));
        L3(i) = v2(i) + (d/2)*sin(th1(i));
        L4(i) = v2(i) + (d/2)*sin(phy1(i));
        L2(i) = v2(i) - (d/2)*sin(phy1(i));
    end

    l1 = L1(31) + L1(32) + L1(33) + L1(34) + L1(35) + L1(36) + L1(37) + L1(38) + L1(39) + L1(40) + 3*L0;
    l2 = L2(31) + L2(32) + L2(33) + L2(34) + L2(35) + L2(36) + L2(37) + L2(38) + L2(39) + L2(40) + 3*L0;
    l3 = L3(31) + L3(32) + L3(33) + L3(34) + L3(35) + L3(36) + L3(37) + L3(38) + L3(39) + L3(40) + 3*L0;
    l4 = L4(31) + L4(32) + L4(33) + L4(34) + L4(35) + L4(36) + L4(37) + L4(38) + L4(39) + L4(40) + 3*L0;
    l_first = [l1 l2 l3 l4]
      
    for i=1:1:(N2+N3+N4)
        u(i,1)=u((i+N1),1);
        u(i,2)=u((i+N1),2);
        u(i,3)=u((i+N1),3);
        v(i,1)=v((i+N1),1);
        v(i,2)=v((i+N1),2);
        v(i,3)=v((i+N1),3);
    end      

    for i=31:1:40
        u(31,1)= u(30,1) + l*sin(i*th1(i)); 
        u(31,2)= u(30,2) + l*sin(i*phy1(i));
        u(31,3)= u(30,3) + l*cos(i*th1(i))*cos(i*phy1(i));
    end
    for i=32:1:40
        u(i,1) = u((i-1),1) + l*sin(i*th1(i)); 
        u(i,2) = u((i-1),2) + l*sin(i*phy1(i));
        u(i,3) = u((i-1),3) + l*cos(i*th1(i))*cos(i*phy1(i));
    end


    for i=1:1:(N1+N2+N3+N4)
        quiver3(u(i,1),u(i,2),u(i,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
        hold on;   
    end
    hold off;
      
    k=k+1;

    for i=1:1:30
    th1(i) = th1(i+10);
    phy1(i) = th1(i+10);
    end

    % Now length calculation is as follows:
    for i=1:1:30
        v3(i) = sqrt((v(i,1)^2)+(v(i,2)^2)+(v(i,3)^2)); % This will give the array of vector length 
    end
  
    for i=21:1:30
        if p1>p2
            L21(i) = v3(i) - (d/2)*cos(alpha2)*sin(th1(21)) ;
            L23(i) = v3(i) + (d/2)*cos(alpha2)*sin(th1(21)) ;
            L24(i) = v3(i) + (d/2)*sin(alpha2)*sin(phy1(21)) - ((d/2)-(d/2)*cos(alpha2))*sin(th1(21));
            L22(i) = v3(i) - (d/2)*sin(alpha2)*sin(phy1(21)) + ((d/2)-(d/2)*cos(alpha2))*sin(th1(21));
        end
        if p2>p1
            L21(i) = v3(i) - (d/2)*sin(alpha2)*sin(th1(21)) - ((d/2)-(d/2)*cos(alpha2))*sin(phy1(21));
            L23(i) = v3(i) + (d/2)*sin(alpha2)*sin(th1(21)) + ((d/2)-(d/2)*cos(alpha2))*sin(phy1(21));
            L24(i) = v3(i) + (d/2)*cos(alpha2)*sin(phy1(21));
            L22(i) = v3(i) - (d/2)*cos(alpha2)*sin(phy1(21));
        end
    end 
    for i=11:1:20
        if p1>p2
            L31(i) = v3(i) - (d/2)*cos(alpha3)*sin(th1(11)) ;
            L33(i) = v3(i) + (d/2)*cos(alpha3)*sin(th1(11)) ;
            L34(i) = v3(i) + (d/2)*sin(alpha3)*sin(phy1(11)) - ((d/2)-(d/2)*cos(alpha3))*sin(th1(11));
            L32(i) = v3(i) - (d/2)*sin(alpha3)*sin(phy1(11)) + ((d/2)-(d/2)*cos(alpha3))*sin(th1(11));
        end
        if p2>p1
            L31(i) = v3(i) - (d/2)*sin(alpha3)*sin(th1(11)) - ((d/2)-(d/2)*cos(alpha3))*sin(phy1(11));
            L33(i) = v3(i) + (d/2)*sin(alpha3)*sin(th1(11)) + ((d/2)-(d/2)*cos(alpha3))*sin(phy1(11));
            L34(i) = v3(i) + (d/2)*cos(alpha3)*sin(phy1(11));
            L32(i) = v3(i) - (d/2)*cos(alpha3)*sin(phy1(11));
        end
    end 
    for i=1:1:10
        if p1>p2
            L41(i) = v3(i) - (d/2)*cos(alpha4)*sin(th1(1)) ;
            L43(i) = v3(i) + (d/2)*cos(alpha4)*sin(th1(1)) ;
            L44(i) = v3(i) + (d/2)*sin(alpha4)*sin(phy1(1)) - ((d/2)-(d/2)*cos(alpha4))*sin(th1(1));
            L42(i) = v3(i) - (d/2)*sin(alpha4)*sin(phy1(1)) + ((d/2)-(d/2)*cos(alpha4))*sin(th1(1));
        end
        if p2>p1
            L41(i) = v3(i) - (d/2)*sin(alpha4)*sin(th1(1)) - ((d/2)-(d/2)*cos(alpha4))*sin(phy1(1));
            L43(i) = v3(i) + (d/2)*sin(alpha4)*sin(th1(1)) + ((d/2)-(d/2)*cos(alpha4))*sin(phy1(1));
            L44(i) = v3(i) + (d/2)*cos(alpha4)*sin(phy1(1));
            L42(i) = v3(i) - (d/2)*cos(alpha4)*sin(phy1(1));
        end
    end 

    l21 = L21(21) + L21(22) + L21(23) + L21(24) + L21(25) + L21(26) + L21(27) + L21(28) + L21(29) + L21(30) + 2*L0 ;
    l22 = L22(21) + L22(22) + L22(23) + L22(24) + L22(25) + L22(26) + L22(27) + L22(28) + L22(29) + L22(30)  + 2*L0;
    l23 = L23(21) + L23(22) + L23(23) + L23(24) + L23(25) + L23(26) + L23(27) + L23(28) + L23(29) + L23(30)  + 2*L0;
    l24 = L24(21) + L24(22) + L24(23) + L24(24) + L24(25) + L24(26) + L24(27) + L24(28) + L24(29) + L24(30)  + 2*L0;

    l31 = L31(11) + L31(12) + L31(13) + L31(14) + L31(15) + L31(16) + L31(17) + L31(18) + L31(19) + L31(20)  + L0 ;
    l32 = L32(11) + L32(12) + L32(13) + L32(14) + L32(15) + L32(16) + L32(17) + L32(18) + L32(19) + L32(20)  + L0;
    l33 = L33(11) + L33(12) + L33(13) + L33(14) + L33(15) + L33(16) + L33(17) + L33(18) + L33(19) + L33(20)  + L0;
    l34 = L34(11) + L34(12) + L34(13) + L34(14) + L34(15) + L34(16) + L34(17) + L34(18) + L34(19) + L34(20)  + L0;

    l41 = L41(1) + L41(2) + L41(3) + L41(4) + L41(5) + L41(6) + L41(7) + L41(8) + L41(9) + L41(10);
    l42 = L42(1) + L42(2) + L42(3) + L42(4) + L42(5) + L42(6) + L42(7) + L42(8) + L42(9) + L42(10);
    l43 = L43(1) + L43(2) + L43(3) + L43(4) + L43(5) + L43(6) + L43(7) + L43(8) + L43(9) + L43(10);
    l44 = L44(1) + L44(2) + L44(3) + L44(4) + L44(5) + L44(6) + L44(7) + L44(8) + L44(9) + L44(10);

    format short g
    l_final = [l1 l2 l3 l4;l21 l22 l23 l24;l31 l32 l33 l34;l41 l42 l43 l44]
    % sprintf('%f',l_final)
    end
    
    if (y=='p')
        break;
    end
end
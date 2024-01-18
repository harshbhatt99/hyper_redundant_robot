close all;
clear all;
clc;

links = 10;
l = 25; d = 35;
p=0;
theta_deg=0; th1_deg=0;
phy_deg=0; phy1_deg=0;
n = 0;r=0;count=1;
th1=0;
phy1=0;
c=0; %for switching between continuous loop of only straingt forward motion and curved motion

for i=1:1:links
   u(i,1)=0; %x co-ordinate of base points
   u(i,2)=0; %y co-ordinate of base points
   u(i,3)=n*l; %z co-ordinate of base points
   
   u1(i,1)=17.5; % x co-ordinate of base point of wire-1 up
   u1(i,2)=0; %y co-ordinate of base points of wire-1 up
   u1(i,3)=n*l; %z co-ordinate of base points of wire-1 up
   
   u3(i,1)= -17.5; % x co-ordinate of base point of wire-3 down
   u3(i,2)=0; %y co-ordinate of base points of wire-3 down
   u3(i,3)=n*l; %z co-ordinate of base points of wire-3 down
   
   v(i,1)=l*sin(th1); %vector length in x-dir
   v(i,2)=l*sin(phy1); %vector length in y-dir
   v(i,3)=l*cos(th1)*cos(phy1); %vector length in z-dir
   
   v1(i,1)=l*sin(th1); %vector length in x-dir of wire-1 up
   v1(i,2)=l*sin(phy1); %vector length in y-dir of wire-1 up
   v1(i,3)=l*cos(th1)*cos(phy1); %vector length in z-dir of wire-1 up
   
   v3(i,1)=l*sin(th1); %vector length in x-dir of wire-3 down
   v3(i,2)=l*sin(phy1); %vector length in y-dir of wire-3 down
   v3(i,3)=l*cos(th1)*cos(phy1); %vector length in z-dir of wire-3 dowm
   n = n+1;
end
for i=1:1:links
   quiver3(u(i,1),u(i,2),u(i,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
   hold on;
   quiver3(u1(i,1),u1(i,2),u1(i,3),v1(i,1),v1(i,2),v1(i,3),0,'ShowArrowHead','off','LineWidth',3.5)
   hold on;
   quiver3(u3(i,1),u3(i,2),u3(i,3),v3(i,1),v3(i,2),v3(i,3),0,'ShowArrowHead','off','LineWidth',3.5)
   hold on;
end
hold off;
% This commented part is for only forward motion which is for now pending
% as only forward motion in z-dir whill be controlled seperately

    x = input('Move forward with l or press t to switch to rotation loop: ','s')
    if x=='l' % for now l will just be used to move in z-dir without turning
   
    for i=1:1:(links-1)
        u(i,3)=u((i+1),3)
        quiver3(u(i,1),u(i,2),u(i,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
        hold on;
        quiver3(u1(i,1),u1(i,2),u1(i,3),v1(i,1),v1(i,2),v1(i,3),0,'ShowArrowHead','off','LineWidth',3.5)
        hold on;
        quiver3(u3(i,1),u3(i,2),u3(i,3),v3(i,1),v3(i,2),v3(i,3),0,'ShowArrowHead','off','LineWidth',3.5)
        hold on;
    end
        u(links,3)=n*l; 
        u1(links,3)=n*l;
        u3(links,3)=n*l;
        
        quiver3(u(links,1),u(links,2),u(links,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5);
        hold on;
        quiver3(u1(links,1),u1(links,2),u1(links,3),v1(i,1),v1(i,2),v1(i,3),0,'ShowArrowHead','off','LineWidth',3.5);
        hold on;
        quiver3(u3(links,1),u3(links,2),u3(links,3),v3(i,1),v3(i,2),v3(i,3),0,'ShowArrowHead','off','LineWidth',3.5);
        hold off;
    end
   
while 1
    if r==0
    y = input('Turn(w/s/a/d) or q to switch to forward loop: ','s')
    if (y=='w' || y=='s' || y=='a' || y=='d') % This condition is used to define increamental values of theta
        if y=='w'
            theta_deg =  th1_deg + 10;
        end
        if y=='s'
            theta_deg = th1_deg - 10;
        end
        if y=='a'
            phy_deg = phy1_deg + 10;
        end
        if y=='d'
            phy_deg = phy1_deg - 10;
        end

        th1_deg = theta_deg;
        th1 = th1_deg * (pi/180);
        phy1_deg = phy_deg;
        phy1 = phy1_deg * (pi/180);
            
        v(links,1)=l*sin(th1);
        v(links,2)=l*sin(phy1);
        v(links,3)=l*cos(th1)*cos(phy1);
        % CHANGE HERE
        
        v1(links,1)=l*sin(th1) - d*tan(th1)*sin(th1);
        v1(links,2)=l*sin(phy1);
        v1(links,3)=l*cos(th1)*cos(phy1) - d*tan(th1)*cos(th1);
            
        v3(links,1)=l*sin(th1) + d*tan(th1)*sin(th1);
        v3(links,2)=l*sin(phy1);
        v3(links,3)=l*cos(th1)*cos(phy1) + d*tan(th1)*cos(th1);
        
        quiver3(u(links,1),u(links,2),u(links,3),v(links,1),v(links,2),v(links,3),0,'ShowArrowHead','off','LineWidth',3.5);
        hold on;
        quiver3(u1(links,1),u1(links,2),u1(links,3),v1(links,1),v1(links,2),v1(links,3),0,'ShowArrowHead','off','LineWidth',3.5);
        hold on;
        quiver3(u3(links,1),u3(links,2),u3(links,3),v3(links,1),v3(links,2),v3(links,3),0,'ShowArrowHead','off','LineWidth',3.5);
        hold on;
        for i=1:1:(links-1)
            quiver3(u(i,1),u(i,2),u(i,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
            hold on;
            quiver3(u1(i,1),u1(i,2),u1(i,3),v1(i,1),v1(i,2),v1(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
            hold on;
            quiver3(u3(i,1),u3(i,2),u3(i,3),v3(i,1),v3(i,2),v3(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
            hold on;    
        end
            hold off;            
    end 

    if y=='q'
        r=1;p=0; 
    end
    if count==1
        u(links,1)=0; 
        u(links,2)=0;
        u(links,3)= ((n-2)*l) + l*cos(th1)*cos(phy1);
        
        u1(links,1)=17.5 ; 
        u1(links,2)=0;
        u1(links,3)= ((n-2)*l) + l*cos(th1)*cos(phy1);
        
        u3(links,1)= -17.5; 
        u3(links,2)=0;
        u3(links,3)= ((n-2)*l) + l*cos(th1)*cos(phy1);
    end
    count=count+1;
end
       
if r==1    
    x = input('Move forward m or e to switch to turning loop: ','s')       
    if x =='m'
           
        v(links-p,1)= l*sin(th1);
        v(links-p,2)= l*sin(phy1);
        v(links-p,3)= l*cos(th1)*cos(phy1);
        
        v1(links-p,1)= l*sin(th1) - d*tan(th1)*sin(th1);
        v1(links-p,2)= l*sin(phy1);
        v1(links-p,3)= l*cos(th1)*cos(phy1) - d*tan(th1)*cos(th1);
        
        v3(links-p,1)= l*sin(th1) + d*tan(th1)*sin(th1);
        v3(links-p,2)= l*sin(phy1);
        v3(links-p,3)= l*cos(th1)*cos(phy1) + d*tan(th1)*cos(th1);
    
        p=p+1;
      
        for i=1:1:(links-1)
            u(i,1)=u((i+1),1);
            u(i,2)=u((i+1),2);
            u(i,3)=u((i+1),3);
            
            u1(i,1)=u1((i+1),1);
            u1(i,2)=u1((i+1),2);
            u1(i,3)=u1((i+1),3);
            
            u3(i,1)=u3((i+1),1);
            u3(i,2)=u3((i+1),2);
            u3(i,3)=u3((i+1),3);
         
            v(i,1)=v((i+1),1);
            v(i,2)=v((i+1),2);
            v(i,3)=v((i+1),3);
            
            v1(i,1)=v1((i+1),1);
            v1(i,2)=v1((i+1),2);
            v1(i,3)=v1((i+1),3);
            
            v3(i,1)=v3((i+1),1);
            v3(i,2)=v3((i+1),2);
            v3(i,3)=v3((i+1),3);
        end

        u(links,1)= u(links,1) + l*sin(th1);   
        u(links,2)= u(links,2) + l*sin(phy1);
        u(links,3)= u(links,3) + l*cos(th1)*cos(phy1);
        
        u1(links,1)= u1(links,1) + l*sin(th1);   
        u1(links,2)= u1(links,2) + l*sin(phy1);
        u1(links,3)= u1(links,3) + l*cos(th1)*cos(phy1);    
        
        u3(links,1)= u3(links,1) + l*sin(th1);   
        u3(links,2)= u3(links,2) + l*sin(phy1);
        u3(links,3)= u3(links,3) + l*cos(th1)*cos(phy1); 
      
        for i=1:1:links
            quiver3(u(i,1),u(i,2),u(i,3),v(i,1),v(i,2),v(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
            hold on; 
            quiver3(u1(i,1),u1(i,2),u1(i,3),v1(i,1),v1(i,2),v1(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
            hold on; 
            quiver3(u3(i,1),u3(i,2),u3(i,3),v3(i,1),v3(i,2),v3(i,3),0,'ShowArrowHead','off','LineWidth',3.5) 
            hold on;
        end
        hold off;     
    end
    if x=='e'
            r=0;
    end  
end
if (y=='p' || x=='p')
    break;
end
end




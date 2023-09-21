#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
String s;

bool condition;


String b="38007643202D";

String pot_Data;
String amount;


void setup()
{
  
    Serial.begin(9600);
    lcd.begin(16,2);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    lcd.setCursor(0,0);
    lcd.print("SMART CHARGING ");
    lcd.setCursor(0,1);
    lcd.print("EV SYSTEM         ");
    delay(2000);
    pinMode(A5,INPUT);
    pinMode(7,INPUT);
    pinMode(6,INPUT);
    pinMode(5,INPUT);
//    digitalWrite(3,LOW);

    lcd.clear();
    
    
}

void loop() 
{

///////////////////////////////////////////////////////////////////////////////////////////////////

 
//  int refSignaBattery = 1;
//  int refGridnormal = 1; 
//  int refGridPeak = 1;
                            
  int  a=analogRead(A0); //unit cost
  
  int  battery=digitalRead(7);  // battery cost
    
  int  gridNormal=digitalRead(6);  // normal time grid charging cost
  
  int  gridPeak=digitalRead(5);  // peak time grid charging cost         
              
             

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

             
  // int batterylogic = gridNormal == 0 && gridPeak==0;
  
      if (battery ==0 && gridNormal == 1 && gridPeak==1 )
        {

          lcd.setCursor(8,1);
          lcd.print("Battery   ");
    

         if(a==0)
              {
             
                
                      lcd.setCursor(0,0);
                      lcd.print("U:0 ");
                      lcd.setCursor(5,0);
                      lcd.print("                ");
                    
                      pot_Data = "U_0";
                    
               lcd.setCursor(0,1);
                    lcd.print("       ");

                          digitalWrite(3,LOW); 
                
              }
              else if(a>100 && a<200)
              {
                
                       lcd.setCursor(0,0);
                       lcd.print("U:5 ");
                    
                       lcd.setCursor(5,0);
                       lcd.print("C-25 ");
                    
                    
                       lcd.setCursor(11,0);
                       lcd.print("10min");
                       
                       lcd.setCursor(0,1);
                    lcd.print("       ");

                       pot_Data = "10Min_U_5_Cost_25";


                          digitalWrite(3,LOW); 
              
              }
                
              else if(a>200 && a<300)
              {
                
                lcd.setCursor(0,0);
                lcd.print("U:8 ");
              
                lcd.setCursor(5,0);
                lcd.print("C-42 ");
              
               
                lcd.setCursor(11,0);
                  lcd.print("15min");

                                 lcd.setCursor(0,1);
                    lcd.print("       ");


               pot_Data = "15Min_U_8_Cost_42";
              
              
                          digitalWrite(3,LOW); 
                
              }
              else if(a>300 && a<400)
              {
                
                      lcd.setCursor(0,0);
                      lcd.print("U:13");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-67 ");
                    
                     
                         lcd.setCursor(11,0);
                         lcd.print("20min        ");

                                        lcd.setCursor(0,1);
                    lcd.print("       ");

                         pot_Data = "20Min_U_13_Cost_67";

                    
                          digitalWrite(3,LOW); 
                 
              }
              else if(a>400 && a<500)
              {
                
                    lcd.setCursor(0,0);
                    lcd.print("U:17");
                  
                    lcd.setCursor(5,0);
                    lcd.print("C-105");
                    lcd.setCursor(11,0);
                    lcd.print("25min        ");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                     pot_Data = "25Min_U_17_Cost_105";

                       
                          digitalWrite(3,LOW); 
              }
              else if(a>500 && a<600)
              {
              
                      lcd.setCursor(0,0);
                      lcd.print("U:25");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-140");
                      lcd.setCursor(11,0);
                      lcd.print("30min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                      pot_Data ="30Min_U_25_Cost_140";
                    
               
                          digitalWrite(3,LOW); 
              }
              else if(a>600 && a<700)
              {
                      lcd.setCursor(0,0);
                      lcd.print("U:29");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-180");
                      lcd.setCursor(11,0);
                      lcd.print("35min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                      pot_Data ="35Min_U_29_Cost_180";

                      
                          digitalWrite(3,LOW); 

                }
              else if(a>700 && a<800)
              {
                      lcd.setCursor(0,0);
                      lcd.print("U:35");
                      
                      lcd.setCursor(5,0);
                      lcd.print("C-250");
                      
                      lcd.setCursor(11,0);
                        
                      lcd.print("40min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                      pot_Data ="40Min_U_35_Cost_250";

                      
                          digitalWrite(3,LOW); 
              }
              
              else if(a>800 && a<900)
              {
                
                    lcd.setCursor(0,0);
                    lcd.print("U:43");
                  
                    lcd.setCursor(5,0);
                    lcd.print("C-346");
                    lcd.setCursor(11,0);
                    lcd.print("45min");

                    pot_Data ="45Min_U_43_Cost_346";
               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                  digitalWrite(3,LOW); 
                 
              }
              else if(a>900)
              {
                    lcd.setCursor(0,0);
                    lcd.print("U:50");
                  
                    lcd.setCursor(5,0);
                    lcd.print("C-500");
                    lcd.setCursor(11,0);
                    lcd.print("50min");

                    pot_Data ="50Min_U_50_Cost_500";
                  
                      
                    lcd.setCursor(0,1);
                    lcd.print("B:Full");
                  
                    digitalWrite(3,LOW); 
              
                
               }
              
              
                     
               
              
                
              if(Serial.available()>0)
              {
                            s=Serial.readString();
                          
//                         Serial.print(s);
                            if(s==b)
                            {
                              amount ="AMOUNT_PAID";
                          
                                      lcd.setCursor(0,0);
                                      lcd.print("Amount Paid         ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Success             ");
                                    
                                      delay(3000);  
                                      lcd.clear();
                                      delay(2000);
                                      
                                      lcd.setCursor(0,0);
                                      lcd.print("Motor UnLocked      ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Success             ");

                                      delay(2000);
                                    
                                      digitalWrite(3,HIGH); 

                                      delay(5000);
                                      
                                      digitalWrite(3,HIGH);  

                            }
                            else{
                              amount = " AMOUNT_NOT_PAID ";
                              lcd.setCursor(0,0);
                                      lcd.print("Amount not Paid         ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Failure            ");
                                    
                                      delay(2000);  
                                      lcd.clear();
                                      delay(2000);
                                      
                                      lcd.setCursor(0,0);
                                      lcd.print("Motor UnLocked      ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Failure             ");

                                      delay(2000);
                                      
                                      digitalWrite(3,LOW); 

                                      delay(4000);

                                      digitalWrite(3,LOW);  
                            }
                 } 
              
             }


///////////////////////////////////////////////////////////////////////////////////////////////////////////
             
              
           else if (gridNormal ==0 && battery==1 && gridPeak ==1)
           {

                lcd.setCursor(8,1);
          lcd.print("Grid_Nor  ");

                if(a==0)
              {
                
                      lcd.setCursor(0,0);
                      lcd.print("U:0 ");
                      lcd.setCursor(5,0);
                      lcd.print("                ");
                    
                      pot_Data = "U_0";
                    
               lcd.setCursor(0,1);
                    lcd.print("       ");

                          digitalWrite(3,LOW); 
                
              }
              else if(a>100 && a<200)
              {
                
                       lcd.setCursor(0,0);
                       lcd.print("U:5 ");
                    
                       lcd.setCursor(5,0);
                       lcd.print("C-30 ");
                    
                    
                       lcd.setCursor(11,0);
                       lcd.print("10min");
                                      lcd.setCursor(0,1);
                    lcd.print("       ");

                       pot_Data = "10Min_U_5_Cost_30";


                          digitalWrite(3,LOW); 
              
              }
                
              else if(a>200 && a<300)
              {
                
                lcd.setCursor(0,0);
                lcd.print("U:8 ");
              
                lcd.setCursor(5,0);
                lcd.print("C-47 ");
              
               
                lcd.setCursor(11,0);
                  lcd.print("15min");

                                 lcd.setCursor(0,1);
                    lcd.print("       ");


               pot_Data = "15Min_U_8_Cost_47";
              
              
                          digitalWrite(3,LOW); 
                
              }
              else if(a>300 && a<400)
              {
                
                      lcd.setCursor(0,0);
                      lcd.print("U:13");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-72 ");
                    
                     
                         lcd.setCursor(11,0);
                         lcd.print("20min        ");

                                        lcd.setCursor(0,1);
                    lcd.print("       ");

                         pot_Data = "20Min_U_13_Cost_72";

                    
                          digitalWrite(3,LOW); 
                 
              }
              else if(a>400 && a<500)
              {
                
                    lcd.setCursor(0,0);
                    lcd.print("U:17");
                  
                    lcd.setCursor(5,0);
                    lcd.print("C-110");
                    lcd.setCursor(11,0);
                    lcd.print("25min        ");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                     pot_Data = "25Min_U_17_Cost_110";

                       
                          digitalWrite(3,LOW); 
              }
              else if(a>500 && a<600)
              {
              
                      lcd.setCursor(0,0);
                      lcd.print("U:25");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-145");
                      lcd.setCursor(11,0);
                      lcd.print("30min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                      pot_Data ="30Min_U_25_Cost_145";
                    
               
                          digitalWrite(3,LOW); 
              }
              else if(a>600 && a<700)
              {
                      lcd.setCursor(0,0);
                      lcd.print("U:29");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-185");
                      lcd.setCursor(11,0);
                      lcd.print("35min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                      pot_Data ="35Min_U_29_Cost_185";

                      
                          digitalWrite(3,LOW); 

                }
              else if(a>700 && a<800)
              {
                      lcd.setCursor(0,0);
                      lcd.print("U:35");
                      
                      lcd.setCursor(5,0);
                      lcd.print("C-255");
                      
                      lcd.setCursor(11,0);
                        
                      lcd.print("40min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                      pot_Data ="40Min_U_35_Cost_255";

                      
                          digitalWrite(3,LOW); 
              }
              
              else if(a>800 && a<900)
              {
                
                    lcd.setCursor(0,0);
                    lcd.print("U:43");
                  
                    lcd.setCursor(5,0);
                    lcd.print("C-351");
                    lcd.setCursor(11,0);
                    lcd.print("45min");

                    pot_Data ="45Min_U_43_Cost_351";
               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                          digitalWrite(3,LOW); 
                 
              }
              else if(a>900)
              {
                    lcd.setCursor(0,0);
                    lcd.print("U:50");
                
                    lcd.setCursor(5,0);
                   lcd.print("C-505");
                    lcd.setCursor(11,0);
                    lcd.print("50min");

                    pot_Data ="50Min_U_50_Cost_505";
                  
                      
                    lcd.setCursor(0,1);
                    lcd.print("B:Full");
                  
                          digitalWrite(3,LOW); 
              
                
               }
              
              
                     
               
              
                
             if(Serial.available()>0)
              {
                            s=Serial.readString();
                          
//                         Serial.print(s);
                            if(s==b)
                            {
                              amount ="AMOUNT_PAID";
                          
                                      lcd.setCursor(0,0);
                                      lcd.print("Amount Paid         ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Success             ");
                                    
                                      delay(3000);  
                                      lcd.clear();
                                      delay(2000);
                                      
                                      lcd.setCursor(0,0);
                                      lcd.print("Motor UnLocked      ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Success             ");

                                      delay(2000);
                                    
                                      digitalWrite(3,HIGH); 

                                      delay(5000);
                                      
                                      digitalWrite(3,HIGH);  

                            }
                            else{
                              amount = " AMOUNT_NOT_PAID ";
                              lcd.setCursor(0,0);
                                      lcd.print("Amount not Paid         ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Failure            ");
                                    
                                      delay(2000);  
                                      lcd.clear();
                                      delay(2000);
                                      
                                      lcd.setCursor(0,0);
                                      lcd.print("Motor UnLocked      ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Failure             ");

                                      delay(2000);
                                      
                                      digitalWrite(3,LOW); 

                                      delay(4000);

                                      digitalWrite(3,LOW);  
                            }
                 }
           }


///////////////////////////////////////////////////////////////////////////////////////////////

           else if (gridPeak ==0  && battery==1 && gridNormal==1)
            // else
           {

                lcd.setCursor(8,1);
          lcd.print("Grid_Peak    ");

                if(a==0)
              {
                
                      lcd.setCursor(0,0);
                      lcd.print("U:0 ");
                      lcd.setCursor(5,0);
                      lcd.print("                ");
                    
                      pot_Data = "U_0";
                    
               lcd.setCursor(0,1);
                    lcd.print("       ");

                          digitalWrite(3,LOW); 
                
              }
              else if(a>100 && a<200)
              {
                
                       lcd.setCursor(0,0);
                       lcd.print("U:5 ");
                    
                       lcd.setCursor(5,0);
                       lcd.print("C-35 ");
                    
                    
                       lcd.setCursor(11,0);
                       lcd.print("10min");
                                      lcd.setCursor(0,1);
                    lcd.print("       ");

                       pot_Data = "10Min_U_5_Cost_35";


                          digitalWrite(3,LOW); 
              
              }
                
              else if(a>200 && a<300)
              {
                
                lcd.setCursor(0,0);
                lcd.print("U:8 ");
              
                lcd.setCursor(5,0);
                lcd.print("C-52 ");
              
               
                lcd.setCursor(11,0);
                  lcd.print("15min");

                                 lcd.setCursor(0,1);
                    lcd.print("       ");


               pot_Data = "15Min_U_8_Cost_52";
              
              
                          digitalWrite(3,LOW); 
                
              }
              else if(a>300 && a<400)
              {
                
                      lcd.setCursor(0,0);
                      lcd.print("U:13");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-77 ");
                    
                     
                         lcd.setCursor(11,0);
                         lcd.print("20min        ");

                                        lcd.setCursor(0,1);
                    lcd.print("       ");

                         pot_Data = "20Min_U_13_Cost_77";

                    
                          digitalWrite(3,LOW); 
                 
              }
              else if(a>400 && a<500)
              {
                
                    lcd.setCursor(0,0);
                    lcd.print("U:17");
                  
                    lcd.setCursor(5,0);
                    lcd.print("C-115");
                    lcd.setCursor(11,0);
                    lcd.print("25min        ");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                     pot_Data = "25Min_U_17_Cost_115";

                       
                          digitalWrite(3,LOW); 
              }
              else if(a>500 && a<600)
              {
              
                      lcd.setCursor(0,0);
                      lcd.print("U:25");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-150");
                      lcd.setCursor(11,0);
                      lcd.print("30min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                      pot_Data ="30Min_U_25_Cost_150";
                    
               
                          digitalWrite(3,LOW); 
              }
              else if(a>600 && a<700)
              {
                      lcd.setCursor(0,0);
                      lcd.print("U:29");
                    
                      lcd.setCursor(5,0);
                      lcd.print("C-190");
                      lcd.setCursor(11,0);
                      lcd.print("35min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                      pot_Data ="35Min_U_29_Cost_190";

                      
                          digitalWrite(3,LOW); 

                }
              else if(a>700 && a<800)
              {
                      lcd.setCursor(0,0);
                      lcd.print("U:35");
                      
                      lcd.setCursor(5,0);
                      lcd.print("C-260");
                      
                      lcd.setCursor(11,0);
                        
                      lcd.print("40min");


               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                      pot_Data ="40Min_U_35_Cost_260";

                      
                          digitalWrite(3,LOW); 
              }
              
              else if(a>800 && a<900)
              {
                
                    lcd.setCursor(0,0);
                    lcd.print("U:43");
                  
                    lcd.setCursor(5,0);
                    lcd.print("C-356");
                    lcd.setCursor(11,0);
                    lcd.print("45min");

                    pot_Data ="45Min_U_43_Cost_356";
               lcd.setCursor(0,1);
                    lcd.print("       ");
                    
                          digitalWrite(3,LOW); 
                 
              }
              else if(a>900)
              {
                    lcd.setCursor(0,0);
                    lcd.print("U:50");
                
                    lcd.setCursor(5,0);
                   lcd.print("C-510");
                    lcd.setCursor(11,0);
                    lcd.print("50min");

                    pot_Data ="50Min_U_50_Cost_510";
                  
                      
                    lcd.setCursor(0,1);
                    lcd.print("B:Full");
                  
                          digitalWrite(3,LOW); 
              
                
               }
              
              
                     
               
              
                
             if(Serial.available()>0)
              {
                            s=Serial.readString();
                          
//                         Serial.print(s);
                            if(s==b)
                            {
                              amount ="AMOUNT_PAID";
                          
                                      lcd.setCursor(0,0);
                                      lcd.print("Amount Paid         ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Success             ");
                                    
                                      delay(3000);  
                                      lcd.clear();
                                      delay(2000);
                                      
                                      lcd.setCursor(0,0);
                                      lcd.print("Motor UnLocked      ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Success             ");

                                      delay(2000);
                                    
                                      digitalWrite(3,HIGH); 

                                      delay(5000);
                                      
                                      digitalWrite(3,HIGH);  

                            }
                            else{
                              amount = " AMOUNT_NOT_PAID ";
                              lcd.setCursor(0,0);
                                      lcd.print("Amount not Paid         ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Failure            ");
                                    
                                      delay(2000);  
                                      lcd.clear();
                                      delay(2000);
                                      
                                      lcd.setCursor(0,0);
                                      lcd.print("Motor UnLocked      ");
                                      lcd.setCursor(0,1);
                                      lcd.print("Failure             ");

                                      delay(2000);
                                      
                                      digitalWrite(3,LOW); 

                                      delay(4000);

                                      digitalWrite(3,LOW);  
                            }
                 }
           }

           ////////////////////////////////////////////////////////////////////////////////////////////////////////////
           
           else
           {
//            lcd.setCursor(0,0);
//            lcd.print("U:5 ");
            
            lcd.setCursor(0,0);
            lcd.print("                      ");
            
            lcd.setCursor(8,1);
          lcd.print("NO_Con        ");
          
            }
            




              String web_data2 = pot_Data+"_"+amount;

              int webdata_len2 = web_data2 .length();
                                                                                    
              String send_data2  = String(webdata_len2)+"_"+web_data2;
                                  
              Serial.print(send_data2);
       delay(3000);
           

}

int old_button = 0;


void setup()
{
  Serial.begin(9600);


} 


void loop ()
{
  int button, button2, pressed_button;  
  button = getButton();
  if (button != old_button)
  {
    delay(50);        // debounce
    button2 = getButton();

    if (button == button2)
    {
      old_button = button;
      pressed_button = button;
      Serial.println(pressed_button);
    }
  }
}

int getButton()
{
  int i, z, sum;
    int button;

  sum = 0;
  for (i=0; i < 4; i++)
  {
    sum += analogRead(0);
  }
  z = sum / 4;
  Serial.println("valeur analog" );
  Serial.print(z);
delay(1000);
  if (z > 1021) button = 0;                                           
  else if (z > 511 && z < 514) button = 1;                     
  else if (z > 680 && z < 684) button = 2;                
  else if (z > 766 && z < 770) button = 3;                
  else if (z > 817 && z < 822) button = 4;             
  else if (z > 851 && z < 856) button = 5; 
  else if (z > 875 && z < 880) button = 6;
  else button = 0;

  return button;
}





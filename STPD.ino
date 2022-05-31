//LED PIN Numbers
const int LedOneNegPin = 12;
const int LedOnePosPin = 13;

//Bluetooth Junk captured
char junk;
//Bluetooth input string variable
String inputString="";

//Bluetooth LED one Signal
String BTcmd_ledOne = "1";
//Bluetooth LED two Signal
String BTcmd_ledTwo = "2";


void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);
  Serial.println(" HC 05 Controller DEMO Start");
  
  pinMode(LedOneNegPin , OUTPUT);
  pinMode(LedOnePosPin , OUTPUT);
  digitalWrite(LedOneNegPin , LOW);
  digitalWrite(LedOnePosPin , LOW);
}

void loop()
{
  if(Serial.available()){
    GetBTinput();
  }

}

void GetBTinput()
{
  Serial.println("Getting Bluetooth Input");
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    while (Serial.available() > 0)  
    { 
      junk = Serial.read() ; 
    }   
    ExecuteBTcmd(inputString);
    inputString = "";
}

//Function to execute bluetooth command
//Provide cmd in the args
void ExecuteBTcmd(String command)
{
  String cmd = command;
  //Serial.println(cmd);
  //cmd.remove(cmd.length()-1);
  //cmd.remove(cmd.length()-1);
  
  Serial.println("");
  Serial.print("Command Recieved: ");
  Serial.println(cmd);
  if(cmd.equals(BTcmd_ledOne))
  {
 Serial.println("LED ONE BT SIGNAL");
 digitalWrite(LedOnePosPin , HIGH);
  }else if(cmd.equals(BTcmd_ledTwo))
    {
      Serial.println("LED TWO BT SIGNAL");
   digitalWrite(LedOnePosPin , LOW);
    }
  Serial.print("Command Execution Success");
}
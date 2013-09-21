
#include <XBee.h>

XBee xbee;
XBeeAddress64 destinationAddress = XBeeAddress64(0x0013a200, 0x4098d70c);
XBeeResponse response;
ZBRxResponse zbrx;
ZBTxRequest zbtx;
ZBTxStatusResponse txStatus = ZBTxStatusResponse();

uint8_t payloadValue = 0;
uint8_t togglePayload[1];

typedef struct
{
  char* name;
  int id;
  XBeeAddress64 address;
} device;

device devices[1];

void toggleGarage(int deviceIndex)
{
  togglePayload[0] = payloadValue++ % 255;
  zbtx = ZBTxRequest(devices[deviceIndex].address, togglePayload, sizeof(togglePayload));
  xbee.send(zbtx);
  
  // Indicate the transmission is in process.
  
  if (xbee.readPacket(500)) 
  {
    // got a response!

    // should be a znet tx status              
    if (xbee.getResponse().getApiId() == ZB_TX_STATUS_RESPONSE) 
    {
      xbee.getResponse().getZBTxStatusResponse(txStatus);

      // get the delivery status, the fifth byte
      if (txStatus.getDeliveryStatus() == SUCCESS) 
      {
        // success.  time to celebrate
        Serial.println("Delivery Success");
      } 
      else 
      {
        // the remote XBee did not receive our packet. is it powered on?
        Serial.println("Transmission Failure");
      }
    }
  } 
  else if (xbee.getResponse().isError()) 
  {
    Serial.print("Error reading packet.  Error code: ");  
    Serial.println(xbee.getResponse().getErrorCode());
  } 
  else 
  {
    Serial.println("Timeout");    
  }
}

void setup()
{
  xbee = XBee();
  Serial.begin(9600);
  //xbee.setSerial(Serial);  
  
  // Initialize list of devices
  devices[0].name = "Left Garage";
  devices[0].id = 0;
  devices[0].address = XBeeAddress64(0x0013a200, 0x4098d70c);
}

void loop()
{
  Serial.println("Sending Toggle");
  
  Serial.println("Sent Toggle");
  delay(5000);
}


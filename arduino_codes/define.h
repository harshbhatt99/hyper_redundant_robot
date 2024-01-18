void SpeedRun(byte Address, int Speed)
{
  Wire.beginTransmission(Address);
  Wire.write(1);
  Wire.write(Speed         & 0xff);
  Wire.write((Speed >>  8) & 0xff);
  Wire.endTransmission();    // stop transmitting
}

void SetMaxSpeed(byte Address, byte Speed)
{
  Wire.beginTransmission(Address);
  Wire.write(0);
  Wire.write(Speed);
  Wire.write(0);
  Wire.endTransmission();
}

void SetDamping(byte Address, byte Damping)
{
  Wire.beginTransmission(Address);
  Wire.write(2);
  Wire.write(Damping);
  Wire.write(0);
  Wire.endTransmission();
  delay(50);    //Required to store settings
}

void MoveAbs(byte Address, long Position)
{
  Wire.beginTransmission(Address);
  Wire.write(4);
  Wire.write(Position         & 0xff);
  Wire.write((Position >>  8) & 0xff);
  Wire.write((Position >> 16) & 0xff);
  Wire.write((Position >> 24) & 0xff);
  Wire.endTransmission();
}

void MoveRel(byte Address, long Position)
{
  Wire.beginTransmission(Address);
  Wire.write(8);
  Wire.write(Position         & 0xff);
  Wire.write((Position >>  8) & 0xff);
  Wire.write((Position >> 16) & 0xff);
  Wire.write((Position >> 24) & 0xff);
  Wire.endTransmission();
}

void SetPos(byte Address, long Position)
{
  Wire.beginTransmission(Address);
  Wire.write(3);
  Wire.write(Position         & 0xff);
  Wire.write((Position >>  8) & 0xff);
  Wire.write((Position >> 16) & 0xff);
  Wire.write((Position >> 24) & 0xff);
  Wire.endTransmission();
}

long ReadPos(void)
{
  
}


class RGB{
private:
int r,g,b;
public:
RGB(int r,int g,int b)
{
    this->r=r;
    this->g=g;
    this->b=b;
}
void UpdateRED(int i)
{
    this->r=i;
}
void UpdateGREEN(int i)
{
    this->g=i;
}
void UpdateBLUE(int i)
{
    this->b=i;
}

int getRED()
{
    return this->r;
}
int getGREEN()
{
    return this->g;
}
int getBLUE()
{
    return this->b;
}
};
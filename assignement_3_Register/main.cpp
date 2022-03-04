/**
 * @file main.cpp
 * @author your name (Fady Nashat)
 * @brief 
 * @version 0.1
 * @date 2022-03-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<map>
#include<math.h>
using namespace std;

#define Read 0
#define Write 1
#define Read_Write 2
#define Reserved 3


/*
    template class to choose the size of register 
*/
template<typename T>
class APIs
{
    private:
        T Reg;      //register
        int bits{sizeof(T)*8};  //no of bits
        map<int,int> permission;//Permissions for each bit
        bool Read_flag{false};  //flag to read permission
        bool Write_flag{false}; //flag to write permission
    public:
        APIs()
        {
            Reg=0;
            for(int i=0;i<bits;i++)
            {
                permission[i]=Read_Write;    //default permission
            }
            Read_flag=true;
            Write_flag=true;
        }

        //ask if it has write permission then ask if the value in range and set the value 
        void setRegisterValue(int val)
        {
            if(Write_flag)
            {
                if(val > pow(2,bits)-1)
                {
                    cout<<"Out Of Range"<<endl;
                }
                else    
                    Reg = val;
            }
            else
            {
                cout<<"No Write Permission"<<endl;
            }
        }

        /*test if reg has Read permission then get the value of Reg*/
        T getRegisterValue()
        {
            if(Read_flag)
            {
                return Reg;
            }
            else
            {
                cout<<"No Read Permission"<<endl;
                return 0;
            }
        }

        /*test if the bit in range 
        test if the bit has write permission 
        set the bit*/
        void setBit(int bitNum)
        {
            if(bitNum<bits)
            {
                if(permission[bitNum]==Write || permission[bitNum]==Read_Write)
                {
                    Reg = Reg|(1<<bitNum);
                }
                else
                {
                    cout<<"No Write Permission"<<endl;
                }
            }
            else
            {
                cout<<"Out OF Range"<<endl;
            }
        }

        /*test if the bit in range
        test if it has write permission
        clear the bit*/
        void clearBit(int bitNum)
        {
            if(bitNum<bits)
            {
                if(permission[bitNum]==Write || permission[bitNum]==Read_Write)
                {
                    Reg = Reg&(~(1<<bitNum));
                }
                else
                {
                    cout<<"No Write Permission"<<endl;
                }
            }
            else
            {
                cout<<"Out OF Range"<<endl;
            }
        }


        /*test if the bit in range
        test if has read permission
        get the bit*/
        int getBit(int bitNum)
        {
            if(bitNum<bits)
            {
                if(permission[bitNum]==Read || permission[bitNum]==Read_Write)
                {
                    return (Reg>>bitNum)&1;
                }
                else
                {
                    cout<<"No Read Permission"<<endl;
                    return 0;
                }
            }
            else
            {
                cout<<"Out OF Range"<<endl;
            }
            return 0;
        }


        /*set the all bits with given permission*/
        void setPermission(int per)     //permission for whole register
        {
            switch (per)
            {
            case Read:
                Read_flag=true;
                Write_flag=false;
                break;
            case Write:
                Read_flag=false;
                Write_flag=true;
                break;
            case Read_Write:
                Read_flag=true;
                Write_flag=true;
                break;
            case Reserved:
                Read_flag=false;
                Write_flag=false;
            }

            if(per<4 && per>=0)
            {
                for(int i=0;i<bits;i++)
                {
                    permission[i]=per;
                }
            }
            else
            {
                cout<<"Wrong Permission"<<endl;
            }
        }

        /*set bit permission*/
        void setPermission(int bitNum,int per)
        {
            
            if(bitNum>=0&&bitNum<bits)
            {
                if(per>=0 && per<4)
                {
                    permission[bitNum]=per;
                }
                else
                {
                    cout<<"Wrong Permission"<<endl;
                }
            }
            else
            {
                cout<<"Bit out of range"<<endl;
            }
            for(int i=0;i<bits;i++)
            {
                if(permission[i]!=Read || permission[i]!=Read_Write)
                {
                    Read_flag=false;
                    break;
                }
                else if(permission[i]!=Write || permission[i]!=Read_Write)
                {
                    Write_flag=false;
                    break;
                }
            }
        }
        
};

int main(void)
{
    cout<<"************Testing the class*************"<<endl;
    APIs <uint8_t> Reg1;
    cout<<"Default value for Register : "<<(int)Reg1.getRegisterValue()<<endl<<endl;
    
    cout<<"Testing SetRegisterValue"<<endl;
    Reg1.setRegisterValue(20);
    Reg1.setRegisterValue(256);
    cout<<"Reg : "<<(int)Reg1.getRegisterValue()<<endl<<endl;

    cout<<"Testing setBit"<<endl;
    Reg1.setBit(1);
    Reg1.setBit(8);     //to test out of range case
    cout<<"Reg : "<<(int)Reg1.getRegisterValue()<<endl<<endl;

    cout<<"Testing getBit"<<endl;
    cout<<"Bit : "<<Reg1.getBit(4)<<endl;
    Reg1.getBit(10);
    cout<<endl<<endl;

    cout<<"Testing clearBit"<<endl;
    Reg1.clearBit(4);
    Reg1.clearBit(15);
    cout<<"Reg : "<<(int)Reg1.getRegisterValue()<<endl<<endl;

    cout<<"Testing Permissions"<<endl;
    //set reg for read only and try to read then write 
    Reg1.setPermission(Read);
    cout<<"Reg : "<<(int)Reg1.getRegisterValue()<<endl;
    Reg1.setRegisterValue(20);      //give error
    cout<<endl<<endl;

    Reg1.setPermission(Write);
    Reg1.getRegisterValue();     //it will give error
    cout<<endl<<endl;

    Reg1.setPermission(Reserved);
    Reg1.setRegisterValue(20);   //it will give error
    Reg1.getRegisterValue();     //it will give error
    cout<<endl<<endl;

    cout<<"Testing permissions for bits"<<endl;
    Reg1.setPermission(0,Read_Write);
    Reg1.setBit(0);
    cout<<"bit 0 : "<<Reg1.getBit(0)<<endl<<endl;
    Reg1.setPermission(1,Read);
    Reg1.clearBit(1);
    cout<<"bit 1 : "<<Reg1.getBit(1)<<endl<<endl;
    Reg1.setPermission(2,Reserved);
    Reg1.setBit(2);
    Reg1.getBit(2);
    cout<<endl<<endl;

    return 0;
}
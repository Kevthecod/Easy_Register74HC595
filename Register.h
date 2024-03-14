#ifndef REGISTER_H_INCLUDED
#define REGISTER_H_INCLUDED
#include "Arduino.h"

    class Register
    {
        private:
            int nbrReg;
            int dataPin;
            int latchPin;
            int clockPin;
            String outReg;
        public:
            Register(int, int, int, int);
            void SetRegPin();
            void initOut();
            void Set(int );
            byte selectOut(int , char );
            void Reset(int );
            byte ToByte(String );
            void OutResol(int ); 
    };
#endif // REGISTER_H_INCLUDED
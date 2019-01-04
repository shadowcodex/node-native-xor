#include "modulefunction.h"
#include <string>
#include <bitset>
#include <iostream>
using namespace std;

std::string modulefunction::exor(std::string value) {
  std:string returnValue ("");
  for (std::size_t i = 0; i < value.size(); ++i)
  {
    bitset<8> set = bitset<8>(value.c_str()[i]); // converts string to bit set - ex: 00100110
    for(int x = 0; x < 8; ++x) {
      int bit1 = set[x];
      int cmp = 1;
      int flip;
      __asm__ ( "xor %%ebx, %%eax;" : "=a" (flip) : "a" (bit1) , "b" (cmp) );
      set[x] = flip;
    }

    // now this most likely will result in a value that is out of scope of a readable char..
    // for human readability only we now will force the value into a readable area of characters
    // no point for this other than demonstration.
    // valid char = 33 -> 126
    unsigned long y = set.to_ulong(); 
    long val = 33;
    for(long z = 0; z < y; ++z) {
      if(val + 1 > 126) {
        val = 33;
      } else {
        ++val;
      }
    }

    
    if(val > 126) {
      std::cout << "yup";
    }
    unsigned char c = static_cast<unsigned char>( val );
    
    returnValue += c;
  }
  return returnValue;
}

Napi::String modulefunction::ExorWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    
    if (info.Length() < 1 || !info[0].IsString()) {
        Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
    } 

    Napi::String value = info[0].As<Napi::String>();
    
    Napi::String returnValue = Napi::String::New(env, modulefunction::exor(value));
    return returnValue;
}

Napi::Object modulefunction::Init(Napi::Env env, Napi::Object exports) 
{
  exports.Set("xor", Napi::Function::New(env, modulefunction::ExorWrapped));
 
  return exports;
}
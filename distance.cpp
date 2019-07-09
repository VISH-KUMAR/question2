#include<napi.h>
#include "distance.h"
struct cordinate{
	double x_cordinate;
	double y_cordinate;
};
typedef struct cordinate cordinate;
std::double distance::distance(cordinate p1, cordinate p2)
{
	vector<double> c1;
	vector<double> c2;
	c1.push_back(p1.x_cordinate);
	c1.push_back(p1.y_cordinate);
	c2.push_back(p2.x_cordinate);
	c2.push_back(p2.y_cordinate);

	float distance;
	distance = sqrt(pow((c1.front() - c2.front()), 2) + pow((c1.back()) - c2.back(), 2));
	//distance = sqrt((p1.front() - p2.front())*(p1.front() - p2.front()) + (p1.back() - p2.back())*(p1.back() - p2.back()));
	return distance;
	
}

Napi::Number distance::distanceWrapped(const Napi::CallbackInfo& info) 
{
  Napi::Env env = info.Env();
  
  if (info.Length() < 2 || !info[0].IsObject() || !info[1].IsObject()) {
       Napi::TypeError::New(env, "Object expected").ThrowAsJavaScriptException();
	} 
   
  Napi::Object first = info[0].As<Napi::Object>();
  Napi::Object second = info[1].As<Napi::Object>(); 
  cordinate cor1;
  cordinate cor2;
  cor1.x_cordinate = first.Get("x"); 
  cor1.y_cordinate = first.Get("y");
  cor2.x_cordinate = second.Get("x");
  cor2.y_cordinate = second.Get("y");
  double returnValue = distance:distance(cor1, cor2)
  
  //Napi::double returnValue = Napi::double::New(env, distance::distance());
  
  return Napi::Number::New(env, returnValue);
}

Napi::Object distance::Init(Napi::Env env, Napi::Object exports) 
{
  exports.Set(
"distance", Napi::Function::New(env, distance::distanceWrapped)
  );
 
  return exports;
}

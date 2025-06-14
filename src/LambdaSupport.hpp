#pragma once

#include <functional>

class LambdaSupport {
 protected:
  std::function<void( int )> lambda_action = nullptr;
  std::function<int( int )> lambda_event = nullptr;

  virtual void lambdaAction( int id ) {
    if ( lambda_action && id >= 0 ) lambda_action( id );
  }

  virtual int lambdaEvent( int id ) {
    if ( lambda_event && id >= 0 ) return lambda_event( id );
    return 0;
  }

 public:
  LambdaSupport& onAction( std::function<void( int )> func ) {
    lambda_action = func;
    return *this;
  }
  LambdaSupport& onEvent( std::function<int( int )> func ) {
    lambda_event = func;
    return *this;
  }
};
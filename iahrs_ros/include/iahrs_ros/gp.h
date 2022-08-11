#ifndef _GP_H_
#define _GP_H_
#include <math.h>
#include <vector>



namespace iahrs_ros
{

class GaussianProcess
{

public:

  GaussianProcess()
  {
    _x = {
      1.58,
      2.367,
      3.055,
      -2.51,
      -1.84,
      -1.15,
      -0.4,
      0.565
    };
    _alpha = {
      6.71793352,
      -22.78289312,
      33.73143814,
      -33.86581277,
      23.08475611,
      -4.62067293,
      14.26050408,
      -4.59168369
      
    };
    _magnitude = 0.171 * 0.171;
  }

  double predict(const double& xstar)
  {
    double ystar = xstar;
    std::vector<double>::const_iterator x_it = _x.begin();
    std::vector<double>::const_iterator alpha_it = _alpha.begin();
    for (x_it, alpha_it; x_it < _x.end(); x_it++, alpha_it++)
    {
      ystar += _magnitude * exp(cos(*x_it - xstar) - 1.0) * (*alpha_it);
    }

    return ystar;
  }

private:

  unsigned int _n;
  double _magnitude;
  double _noise;
  std::vector<double> _x;
  std::vector<double> _alpha;

};


}

#endif // _GP_H_
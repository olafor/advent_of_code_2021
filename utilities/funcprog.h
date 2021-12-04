#ifndef FUNCPROG_H
#define FUNCPROG_H

template <typename F>
auto compose(F f)
{
  return f;
}

template <typename F, typename ...Fs>
  auto compose(F f, Fs ...fs)
{
  return [=](auto x) { return f(compose(fs...)(x)); };
}

#endif

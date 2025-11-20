//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "mp_fluidTestApp.h"
#include "mp_fluidApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
mp_fluidTestApp::validParams()
{
  InputParameters params = mp_fluidApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

mp_fluidTestApp::mp_fluidTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  mp_fluidTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

mp_fluidTestApp::~mp_fluidTestApp() {}

void
mp_fluidTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  mp_fluidApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"mp_fluidTestApp"});
    Registry::registerActionsTo(af, {"mp_fluidTestApp"});
  }
}

void
mp_fluidTestApp::registerApps()
{
  registerApp(mp_fluidApp);
  registerApp(mp_fluidTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
mp_fluidTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  mp_fluidTestApp::registerAll(f, af, s);
}
extern "C" void
mp_fluidTestApp__registerApps()
{
  mp_fluidTestApp::registerApps();
}

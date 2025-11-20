#include "mp_fluidApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
mp_fluidApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

mp_fluidApp::mp_fluidApp(const InputParameters & parameters) : MooseApp(parameters)
{
  mp_fluidApp::registerAll(_factory, _action_factory, _syntax);
}

mp_fluidApp::~mp_fluidApp() {}

void
mp_fluidApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<mp_fluidApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"mp_fluidApp"});
  Registry::registerActionsTo(af, {"mp_fluidApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
mp_fluidApp::registerApps()
{
  registerApp(mp_fluidApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
mp_fluidApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  mp_fluidApp::registerAll(f, af, s);
}
extern "C" void
mp_fluidApp__registerApps()
{
  mp_fluidApp::registerApps();
}

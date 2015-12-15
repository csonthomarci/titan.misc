/******************************************************************************
* Copyright (c) 2004, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributor: david.ferenc.vranics@ericsson.com
******************************************************************************/

#ifndef VS_Logging_External_Functions_HH
#define VS_Logging_External_Functions_HH

#include <TTCN3.hh>

namespace VS__Logging__Functions
{
  void log__debug(CHARSTRING const &msg);
  void log__warning(CHARSTRING const &msg);
  void log__error(CHARSTRING const &msg);
  void log__user(CHARSTRING const &msg);
  void log__testcase(CHARSTRING const &msg);
}

#endif

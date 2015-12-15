#!/bin/sh

###############################################################################
# Copyright (c) 2004, 2015  Ericsson AB
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v1.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v10.html
#
# Contributor: david.ferenc.vranics@ericsson.com
###############################################################################

resolved=$(readlink -f `which $0`)
toolsDir=$(dirname $resolved)
vsbotDir=${toolsDir%/tools}
if [ -x $vsbotDir/bin/vsbot ]
then
  setcap cap_net_raw,cap_net_admin=eip $vsbotDir/bin/vsbot
else
  echo "ERROR: $vsbotDir/bin/vsbot is not executable!"
fi

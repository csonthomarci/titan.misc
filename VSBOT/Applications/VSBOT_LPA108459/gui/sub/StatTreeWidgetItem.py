###############################################################################
# Copyright (c) 2004, 2015  Ericsson AB
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v1.0
# which accompanies this distribution, and is available at
# http://www.eclipse.org/legal/epl-v10.html
#
# Contributor: david.ferenc.vranics@ericsson.com
###############################################################################

#try to import Qt
try:
  import sys
  
  from PyQt4.QtGui import *
  from PyQt4.QtCore import *
except:
  print "\nPlease install python-qt4 package!\n"
  sys.exit(1)

class StatTreeWidgetItem(QTreeWidgetItem):
    def __init__(self, qTreeWidgetItem = None):
        if qTreeWidgetItem == None:
          super(StatTreeWidgetItem, self).__init__()
        else:
          super(StatTreeWidgetItem, self).__init__(qTreeWidgetItem)
        
        self.verdict = "NONE"

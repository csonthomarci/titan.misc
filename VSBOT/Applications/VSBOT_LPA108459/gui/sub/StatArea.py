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
  
from StatWidget import StatWidget

class StatArea(QWidget):
    
    def __init__(self, configured):
        super(StatArea, self).__init__()
        
        self.vLayout = QVBoxLayout()
        
        self.w = StatWidget(configured)
        self.scrollArea = QScrollArea()
        self.scrollArea.setWidget(self.w)
        self.scrollArea.setMinimumHeight(117)
        self.scrollArea.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.scrollArea.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        
        self.configuredTitleLabel = QLabel("Configured p/s:")
        self.configuredValueLabel = QLabel(str(float(configured)))
        self.actualTitleLabel = QLabel("Actual p/s:")
        self.actualValueLabel = QLabel("0.0")
        self.spacer = QSpacerItem(0, 0, QSizePolicy.Expanding, QSizePolicy.Minimum)
        self.hLayout = QHBoxLayout()
        
        self.hLayout.addWidget(self.configuredTitleLabel)
        self.hLayout.addWidget(self.configuredValueLabel)
        self.hLayout.addWidget(self.actualTitleLabel)
        self.hLayout.addWidget(self.actualValueLabel)
        self.hLayout.addSpacerItem(self.spacer)
        
        self.vLayout.addWidget(self.scrollArea)
        self.vLayout.addLayout(self.hLayout)
        
        self.setLayout(self.vLayout)
        
    def newStat(self, y):
        self.w.newStat(y)
        self.scrollArea.horizontalScrollBar().setValue(self.scrollArea.horizontalScrollBar().maximum())
        self.actualValueLabel.setText(str(float(y)))

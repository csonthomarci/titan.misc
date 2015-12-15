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

################################################

class ConsoleView(QTextEdit):
  def __init__(self, parent = None):
    super(ConsoleView, self).__init__(parent)
    self.setReadOnly(True)
    self.setCurrentFont(QFont("Courier New"))
    self.setLineWrapMode(QTextEdit.NoWrap)
    self.setToolTip("The console output appears here.")
       
  def startTITAN(self, filepath, user, host):
    x = filepath.split("/")
    filename = x[len(x) - 1]
    self.setPlainText("")
    self.copyprocess = QProcess()
    self.process = QProcess()
    QObject.connect(self.copyprocess, SIGNAL("readyReadStandardOutput()"), self.readOutput)
    QObject.connect(self.copyprocess, SIGNAL("readyReadStandardError()"), self.readErrors)
    QObject.connect(self.process, SIGNAL("readyReadStandardOutput()"), self.readOutput)
    QObject.connect(self.process, SIGNAL("readyReadStandardError()"), self.readErrors)
    self.copyprocess.start(str("scp " + filepath + " " + user + "@" + host + ":~/VSBOT/cfg/"))
    self.process.start("ssh -t " + user + "@" + host + " bash -i")
    self.process.write(str("cd VSBOT/bin/\n"))
    self.process.write(str("ttcn3_start vsbot ../cfg/" + filename + "\n"))
    self.process.write(str("exit\n"))
  
  def readOutput(self):
    while not self.process.atEnd():
      self.setPlainText(self.toPlainText() + self.process.readLine())
      c =  self.textCursor()
      c.movePosition(QTextCursor.End)
      self.setTextCursor(c)
    
  def readErrors(self):
    self.setPlainText(self.toPlainText() + self.process.readAllStandardError())

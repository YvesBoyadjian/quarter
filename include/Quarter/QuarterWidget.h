#ifndef QUARTER_QUARTERWIDGET_H
#define QUARTER_QUARTERWIDGET_H

/**************************************************************************\
 *
 *  This file is part of the SIM Quarter extension library for Coin.
 *  Copyright (C) 1998-2007 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License ("GPL") version 2
 *  as published by the Free Software Foundation.  See the file COPYING
 *  at the root directory of this source distribution for additional
 *  information about the GNU GPL.
 *
 *  For using SIM Quarter with software that can not be combined with
 *  the GNU GPL, and for taking advantage of the additional benefits of
 *  our support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion AS, Bygd�y all� 5, N-0257 Oslo, NORWAY. (www.sim.no)
 *
\**************************************************************************/

#include <QGLWidget>
#include <Inventor/SbBasic.h>
#include <Quarter/Basic.h>

class SoNode;
class SoEvent;
class SoCamera;
class SoSceneManager;
class NbSceneManager;

namespace SIM { namespace Coin3D { namespace Quarter {

class DeviceManager;

class QUARTER_DLL_API QuarterWidget : public QGLWidget {
  typedef QGLWidget inherited;
  Q_OBJECT

public:
  QuarterWidget(QWidget * parent = 0);
  QuarterWidget(QGLContext * context, QWidget * parent = 0);
  ~QuarterWidget();

  virtual void setSceneGraph(SoNode * root);
  virtual void setCamera(SoCamera * camera);
  DeviceManager * getDeviceManager(void) const;
  NbSceneManager * getSceneManager(void) const;
                                                   
public slots:
  virtual void viewAll(void);

protected:
  virtual void resizeGL(int width, int height);
  virtual void initializeGL(void);
  virtual void paintGL(void);
  virtual bool event(QEvent * event);
  virtual void actualRedraw(void);

  static void renderCB(void * closure, SoSceneManager *);

private:
  void constructor(void);
  friend class QuarterWidgetP;
  class QuarterWidgetP * pimpl;
};

}}} // namespace

#endif // QUARTER_QUARTERWIDGET_H
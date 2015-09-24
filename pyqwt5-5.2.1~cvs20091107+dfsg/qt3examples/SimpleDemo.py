#!/usr/bin/env python

# The Python version of Qwt-5.0.0/examples/simple


# for debugging, requires: python configure.py  --trace ...
if False:
    import sip
    sip.settracemask(0x3f)

import math
import sys
import qt
import Qwt5 as Qwt


class SimpleData(Qwt.QwtData):

    def __init__(self, function, size):
        Qwt.QwtData.__init__(self)
        self.__function = function
        self.__size = size

    def copy(self):
        return self

    def size(self):
        return self.__size

    def x(self, i):
        return 0.1*i

    def y(self, i):
        return self.__function(self.x(i))

# class SimpleData


class SimplePlot(Qwt.QwtPlot):

    def __init__(self, *args):
        Qwt.QwtPlot.__init__(self, *args)

	# make a QwtPlot widget
	self.setTitle('SimpleDemo.py')
        self.insertLegend(Qwt.QwtLegend(), Qwt.QwtPlot.RightLegend)

        # a variation on the C++ example
        self.plotLayout().setAlignCanvasToScales(True)
        grid = Qwt.QwtPlotGrid()
        grid.attach(self)
        grid.setPen(qt.QPen(qt.Qt.black, 0, qt.Qt.DotLine))
        
	# set axis titles
	self.setAxisTitle(Qwt.QwtPlot.xBottom, 'x -->')
	self.setAxisTitle(Qwt.QwtPlot.yLeft, 'y -->')

	# insert a few curves
	cSin = Qwt.QwtPlotCurve('y = sin(x)')
	cSin.setPen(qt.QPen(qt.Qt.red))
        cSin.attach(self)

	cCos = Qwt.QwtPlotCurve('y = cos(x)')
	cCos.setPen(qt.QPen(qt.Qt.blue))
        cCos.attach(self)
        
	# initialize the data
	cSin.setData(SimpleData(math.sin, 100))
	cCos.setData(SimpleData(math.cos, 100))

	# insert a horizontal marker at y = 0
 	mY = Qwt.QwtPlotMarker()
        mY.setLabel(Qwt.QwtText('y = 0'))
        mY.setLabelAlignment(qt.Qt.AlignRight | qt.Qt.AlignTop)
        mY.setLineStyle(Qwt.QwtPlotMarker.HLine)
        mY.setYValue(0.0)
        mY.attach(self)

 	# insert a vertical marker at x = 2 pi
        mX = Qwt.QwtPlotMarker()
        mX.setLabel(Qwt.QwtText('x = 2 pi'))
        mX.setLabelAlignment(qt.Qt.AlignRight | qt.Qt.AlignTop)
        mX.setLineStyle(Qwt.QwtPlotMarker.VLine)
        mX.setXValue(2*math.pi)
        mX.attach(self)

        # replot
        self.replot()

    # __init__()

# class Plot


def make():
    demo = SimplePlot()
    demo.resize(500, 300)
    demo.show()
    return demo

# make()


def main(args):
    app = qt.QApplication(args)
    demo = make()
    app.setMainWidget(demo)
    sys.exit(app.exec_loop())

# main()


# Admire
if __name__ == '__main__':
    main(sys.argv)

# Local Variables: ***
# mode: python ***
# End: ***




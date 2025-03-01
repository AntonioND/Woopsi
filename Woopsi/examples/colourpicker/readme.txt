ColourPicker Test
-----------------

  This example shows how the ColourPicker class should be used.

  The ColourPicker class allows the developer to quickly create a colour picker.
  It has sliders to set the values of the red, green and blue components.  The
  initially selected date is chosen by the programmer and specified in the
  constructor.

  When the user moves a slider, the calendar raises a value change event.
  Checking for color changes is simply a matter of listening for events from the
  colour picker, and when one is received, checking that it originates from the
  colour picker and that it is a value change event event.


Building the Example
--------------------

  To build this example, open a shell, navigate to this directory, and type
  "make".

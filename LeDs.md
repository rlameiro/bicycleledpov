# Packages #
JpCasainho works in automotive LED lightning and in the company where he works the most used package for LEDs is PLCC4.

# Comparison of 2 LEDs #
  * LED 1 caracteristics: AVAGO TECHNOLOGIES #HSMJ-A100-Q00J1; 200 mcd at 20mA; Vf = 2,2V; [cost 0,116 euros unity on Farnell](http://pt.farnell.com/jsp/search/productdetail.jsp?SKU=4134369).
  * LED 2 caracteristics: Osram Power Top LED #LAE65B: Bin: BB-3-3A-50; 2520 mcd at 50mA; Vf = 2V; [cost 0,85 euros unity on Farnell](http://pt.farnell.com/1226385RL/optoelectronics/product.us0?sku=osram-lae65f-cada-24-1-z).

LED 1 was tested at 20mA and gives a good amount of light for this project. LED 2 at 50mA gives 12,6 times more light than LED 1, however we do not want to use 50mA because is very much current, can be a problem since project will use batteries.

With some math and reading datasheet of booth LEDs, turns out that LED 2 needs just about 5mA to give the 200 mcd as LED 1 at 20mA.

The power used by LED 1 is 0.044W (2,2V `*` 20mA) and by the LED 2, 0.0091W (1,82V `*` 5mA).

In conclusion, using LED 2 instead of using LED 1 would give a save of 4,84 times in power, however, LED 2 is more expensive 7,32 times.

If we use 64 LEDs, the total current used is 1,28A for LED 1 and 0,32A for LED 2.
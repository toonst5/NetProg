# NetProg
De server verwacht alrijd een bericht van shogi>CL>.
De server reageerd altijd met shogi>S>"een is tussen 00000001 99999999">["de opmaak van het shogi bord"]"1 voor white en 0 voor black"
Als de server alleen shogi>CL> krijgt of shogi>CL>[...] zal de server er van uit gaan dat je een nieuwe speler bend en zal je een id geven samen met een starter bort.
het bericht zal er dan zo kunnen uit zien 
shogi>S>01349580>[000000000000000000000000000000000000000011111111192999992933333333399999999999999999999999999944444444495999995966666666600000000000000000000000000000000000000008000000000000000000]1

Als je aant spelen bent en je hebt een zet gemaakt zal se server een bericht verwachten met je id en de bord lay out.
het bericht zal er dan zo kunnen uit zien 
shogi>CL>10000000>[000000000000000000000000000000000000000011111111192999992933333333399999999999999999999994999944449444495999995966666666600000000000000000000000000000000000000008000000000000000000] 

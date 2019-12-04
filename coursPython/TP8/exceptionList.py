varNumerateur,varDenominateur=2,"p"
try :
	Res = varNumerateur / varDenominateur
except NameError :
	print ("Le numerateur ou denominateur est mal (ou pas) définie.")
except TypeError :
 	print ("Le type de variable du numérateur ou dénominateur est incompatible avec votre opération!!")
except ZeroDivisionError :
	print ("La variable du dénominateur vaut 0.")

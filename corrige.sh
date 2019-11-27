#! /bin/bash

total=0
diferencias=""

function CorrigeResto(){
    nombre=$1
    if test -e $nombre.tmp; then
      diff $nombre.tmp $nombre.txt > d1.tmp
      nlin=$(cat d1.tmp|wc -l)
      if test $nlin -eq 0; then
        nota=1
      else
        nota=0
        diferencias="diferencias en fichero salida txt; ejecuta diff $nombre.txt $nombre.tmp"
      fi
    else
      nota=0
      diferencias="no se ha generado $nombre.tmp"
    fi
    rm -rf d?.tmp  
    return $nota
}


compilador=g++
aplicacion=Crucero
fuentes=$(ls *.cc *.h 2>/dev/null)
directorio=practica2-prueba
cantidad=$(ls -1 *.cc *.h|wc -l)
numfuentes=0
nota=0
rm -rf *.tmp  $directorio/*.tmp $directorio/*.terr *.o $directorio/*.o $directorio/*.tmp.err $directorio/p?? $directorio/$aplicacion

for fichero in $fuentes; do
 if test $fichero == InfoTur.cc || test $fichero == Coordenadas.cc || test $fichero == Coleccion.cc || \
 test $fichero == LNear.cc || test $fichero == Localidad.cc || test $fichero == Provincia.cc || test $fichero == Crucero.cc || \
 test $fichero == InfoTur.h || test $fichero == Coordenadas.h || test $fichero == Coleccion.h || \
 test $fichero == LNear.h || test $fichero == Localidad.h || test $fichero == Provincia.h ; then 
  if test -f $fichero; then
  let numfuentes=numfuentes+1
  fi
 fi
done

if test $numfuentes -eq 13 -a $cantidad -eq 13; then
  continuar=true
else
  continuar=false
  echo "Error, ficheros fuente requeridos: InfoTur.cc, InfoTur.h, Coordenadas.cc, Coordenadas.h, Coleccion.cc, Coleccion.h, Localidad.cc, Localidad.h, LNear.cc, LNear.h, Provincia.cc, Provincia.h y Crucero.cc; 0"
fi
if $continuar; then
 make >/dev/null 2> errores.compilacion
 grep "error:" errores.compilacion >numerror 
 numlin=$(cat numerror | wc -l)
 if test $numlin -ne 0; then
  echo "Error de compilacion; 0"
  rm -rf numerror
  make clean >/dev/null
  exit 1
 else
  rm -rf errores.compilacion 
 fi
 rm -rf numerror
 objetos=$(ls *.o)
 mv *.o $directorio
 mv $aplicacion $directorio 2>/dev/null
 cp *.h $directorio
 cd  $directorio
 ficherosprueba=$(ls *.cc)
 total=0
 memoria=0
 for prueba in $ficherosprueba; do
  nombre=$(basename $prueba .cc)
  $compilador -std=c++11 -g -c $prueba 2> $nombre.terr
  $compilador -std=c++11 -o $nombre $objetos $nombre.o 2>> $nombre.terr 
  numlin=$(cat $nombre.terr | wc -l)
  if test $numlin -eq 0; then
   if test -e $nombre.data; then
     $(valgrind ./$aplicacion $nombre.data >$nombre.tmp 2>$nombre.tmp.err)
     sed -i "s/Command: .\/$aplicacion//" $nombre.tmp.err
     sed -i "s/$nombre.data//" $nombre.tmp.err
     grep "$aplicacion1" $nombre.tmp.err >viola.txt
   else
      if test -e $nombre.dat; then
          $(valgrind ./$nombre $nombre.dat >$nombre.tmp 2>$nombre.tmp.err)
          sed -i "s/Command: .\/$nombre//" $nombre.tmp.err
          sed -i "s/$nombre.dat//" $nombre.tmp.err
      else
        $(valgrind ./$nombre >$nombre.tmp 2>$nombre.tmp.err)
        sed -i "s/Command: .\/$nombre//" $nombre.tmp.err
      fi
   fi
    grep "$nombre" $nombre.tmp.err >viola.txt
    hayseg=$(cat viola.txt|wc -l)
    if test $hayseg -eq 0; then
      mem=$(grep "definitely lost:" $nombre.tmp.err |sed 's/  */ /g'|cut -d " " -f 4,7)
      cont=0
      c=0
      for var in $mem; do
        if test $var == 0; then
          let c=c+1
        else
          let cont=cont+1
        fi
      done
      if test $cont -gt 0 -a $memoria -eq 0; then
        memoria=1
      else
        true >$nombre.tmp.err
      fi
    fi
    rm -rf viola.txt
   #fi
    numlin=$(cat $nombre.tmp.err|wc -l)
    if test $numlin -eq 0; then
      CorrigeResto $nombre
      nota=$?
      if test $nota -eq 1; then
        echo "Prueba $nombre: Ok"
        total=$(echo "$total+0.5"|bc)
      else
        echo "Prueba $nombre: $diferencias" 
      fi
    else
      echo "Prueba $nombre: Hay errores de ejecucion"
      cat $nombre.tmp.err
    fi
  else
   echo "Prueba $nombre: hay errores de compilacion" 
   cat $nombre.terr
  fi
 rm -rf d1.tmp $nombre.terr 
 done
 total=$(echo "$total"|bc)
 echo "Nota: $total"
 
fi


# Equation-diff-rentielle-m-thode-runge-kutta4
Ce projet simule numériquement le comportement d'un oscillateur de Duffing forcé à l'aide de la méthode de Runge-Kutta d'ordre 4.
Attention ce projet ne fonctionne pas sur Windows
## Modèle mathématique

Le système étudié est défini par l'équation différentielle :

y'' + δy' + αy + βy³ = γ cos(ωt)

Elle est réécrite sous la forme d'un système du premier ordre :

- y₁' = y₂
- y₂' = -δy₂ - αy₁ - βy₁³ + γ cos(ωt)

Les paramètres utilisés sont :

- α = -1
- β = 1
- δ = 0,2
- γ = 1,2
- ω = 1,8

Ce modèle représente un oscillateur non linéaire amorti et soumis à une force périodique.

## Méthode numérique

La fonction `rk4` utilise la méthode de Runge-Kutta d'ordre 4 afin d'approcher les valeurs de `y` et de sa dérivée au cours du temps.

À chaque pas de temps, le programme :

1. calcule quatre approximations intermédiaires ;
2. combine ces approximations ;
3. met à jour les valeurs de `y` et `y'` ;
4. affiche les résultats.

## Compilation

Avec GCC :

```bash
gcc simu104.c -o simu104 -lm
```

Avec le Makefile :
```bash
gcc simu104.c -o simu104 -lm
```

Utilisation
Le programme prend quatre arguments :
```bash
./simu104 durée pas y0 y0'
```
durée : durée totale de la simulation ;
pas : intervalle de temps entre deux calculs ;
y0 : position initiale ;
y0' : vitesse initiale.
Exemple :
```bash
simu104.exe 20 0.01 0.5 1.25
```
Résultats
Le programme affiche trois colonnes :
```bash
Temps (s)    y    dy
```



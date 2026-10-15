# ShootingSystem

## 🎮 Overview

**ShootingSystem** è un progetto personale sviluppato in **Unreal Engine 5**, nato con l'obiettivo di realizzare un sistema di shooting modulare e riutilizzabile all'interno di futuri videogiochi sparatutto.

L'idea è nata durante il **Master in Computer Game Development**, mentre iniziavo ad approfondire lo sviluppo di videogiochi e a progettare alcuni titoli personali, tra cui un possibile survival a tema zombie.

Inizialmente pensavo di sviluppare questi giochi principalmente attraverso **Blueprint Visual Scripting**. Successivamente, approfondendo il linguaggio **C++** durante il Master, ho iniziato a considerare la possibilità di realizzare sistemi di gameplay anche attraverso il codice.

Da questa idea è nato **ShootingSystem**, concepito come una base tecnica indipendente da sviluppare progressivamente e integrare in progetti futuri, evitando di dover ricostruire ogni volta le stesse meccaniche.

Lo sviluppo è stato successivamente interrotto per dare priorità ai diversi progetti e alle consegne del Master.

---

## 🎯 Project Goals

L'obiettivo principale di **ShootingSystem** era costruire un sistema di combattimento FPS riutilizzabile, concentrandosi sull'organizzazione delle meccaniche e sulla possibilità di estenderle nel tempo.

Il progetto prevedeva di approfondire principalmente:

- First Person Character e gestione degli input;
- Weapon System modulare;
- Shooting e Hit Detection attraverso Line Trace;
- Damage e Health System;
- Ammunition e Reload System;
- Fire Rate e differenti modalità di sparo;
- Aiming e Recoil;
- Feedback visivi e sonori;
- Possibile integrazione del Multiplayer/Networking.

L'intenzione non era sviluppare immediatamente un gioco completo, ma costruire progressivamente una base di gameplay da utilizzare in differenti progetti.

---

## 🎮 Controls

### Player

| Input | Azioni |
|---|---|
| `W A S D` | Movimento |
| `Mouse` | Movimento della visuale |
| `Space` | Salto |
| `Crouch Input` | Accovacciarsi |

I controlli relativi alle armi erano previsti per una fase successiva dello sviluppo.

---

## 🕹️ Gameplay

**ShootingSystem** è stato concepito come un prototipo tecnico FPS, nel quale il giocatore avrebbe potuto utilizzare differenti armi per colpire bersagli e interagire con sistemi di combattimento.

Il progetto è stato organizzato partendo dalle funzionalità fondamentali del Character, per poi procedere progressivamente verso l'implementazione delle meccaniche di shooting.

### First Person Character

La prima parte dello sviluppo si è concentrata sulla realizzazione di un Character in prima persona attraverso **Blueprint Visual Scripting**.

Sono state implementate le principali funzionalità di movimento:

- Movimento del personaggio;
- Controllo della visuale;
- Salto;
- Crouch;
- Camera in prima persona;
- Gestione degli input attraverso Enhanced Input.

Questa prima fase ha permesso di costruire una base funzionante sulla quale sviluppare successivamente il sistema di combattimento.

### Shooting System

La fase successiva prevedeva la creazione di un sistema di

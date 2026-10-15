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

La fase successiva prevedeva la creazione di un sistema di armi capace di gestire lo sparo attraverso Line Trace, individuare gli oggetti colpiti e applicare eventuali danni.

L'architettura era pensata per separare le responsabilità del Character da quelle delle armi, facilitando l'aggiunta di differenti tipologie di equipaggiamento.

### Weapon Management

Il sistema avrebbe dovuto comprendere la gestione delle munizioni, la ricarica, la frequenza di sparo e la possibilità di estendere il comportamento delle armi.

Queste funzionalità rappresentavano parte della roadmap e non sono state completate nella versione attuale.

---

## 🧠 Development Focus

Una parte importante del progetto era dedicata allo studio dell'organizzazione dei sistemi di gameplay in Unreal Engine.

Lo sviluppo iniziale è stato realizzato utilizzando **Blueprint Visual Scripting**, con particolare attenzione a:

- Character e Camera Components;
- Enhanced Input System;
- Gestione degli input del giocatore;
- Character Movement;
- Organizzazione dei Blueprint.

La possibilità di utilizzare **C++** rappresentava un'ulteriore evoluzione del progetto, con l'obiettivo di approfondire lo sviluppo di sistemi più strutturati e riutilizzabili.

L'idea era arrivare progressivamente a un'architettura nella quale Character, armi e sistemi di combattimento avessero responsabilità separate.

---

## 📌 Final Considerations

**ShootingSystem** è nato principalmente dal desiderio di realizzare una base tecnica da riutilizzare nei miei futuri progetti personali.

Durante lo sviluppo ho iniziato a comprendere meglio l'importanza di organizzare le funzionalità di gameplay in sistemi indipendenti, piuttosto che costruirle esclusivamente per un singolo videogioco.

Il progetto mi ha inoltre accompagnato in una fase di apprendimento durante la quale stavo passando da uno sviluppo prevalentemente basato sui Blueprint a una maggiore conoscenza del C++.

A causa degli impegni legati al Master, lo sviluppo è stato interrotto prima del completamento delle meccaniche principali di shooting.

Nonostante questo, il progetto rimane un punto di partenza interessante per approfondire in futuro il **Gameplay Programming** e lo sviluppo di sistemi FPS modulari.

---

## 🔮 Future Developments

L'obiettivo futuro è riprendere lo sviluppo del progetto e completare le funzionalità originariamente previste.

Tra i principali sviluppi sono presenti:

- **Weapon System:** implementazione di una classe base per gestire differenti tipologie di armi;
- **Shooting:** sistema di sparo basato su Line Trace e Hit Detection;
- **Damage System:** gestione dei danni e della salute dei bersagli;
- **Ammunition:** caricatore, munizioni disponibili e ricarica;
- **Fire Modes:** introduzione di modalità di sparo semiautomatiche e automatiche;
- **Aiming:** sistema di mira e controllo del Recoil;
- **Visual and Audio Feedback:** effetti di sparo, impatto e suoni;
- **C++ Implementation:** possibile riorganizzazione dei sistemi attraverso classi C++;
- **Multiplayer:** studio della replicazione e della gestione degli spari in rete.

L'obiettivo finale rimane quello di costruire un sistema di shooting modulare, facilmente estendibile e utilizzabile come base per futuri videogiochi FPS.

---

## 📸 Video & Media

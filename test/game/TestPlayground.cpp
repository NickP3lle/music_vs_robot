#include "main.h"

// controllare se un robot si sposta nella colonna dei danni e nel caso
// calcolare i danni che si prende

Playground *get() {
  Playground::cleanUp();
  return Playground::getInstance();
}

bool TestInsertEnemy() {
  get()->enemyInsert(0, 1);
  return true;
}

bool TestInsertPlayer() {
  Playground *tmp = get();
  // dobbiamo avere abbastanza soldi per inserire uno strumento
  Cash::add(Flute().getCost());
  Flute flute;
  if (!tmp->playerInsert(0, 0, &flute))
    return false;
  if (tmp->playerInsert(0, 0, &flute))
    return false;
  Cash::add(Flute().getCost());
  if (!tmp->playerInsert(0, 1, &flute))
    return false;
  return true;
}

bool TestLose() {
  Playground *tmp = get();
  tmp->enemyInsert(2, 5);
  if (tmp->lose())
    return false;
  for (u32 i = 0; i < 60; i++)
    tmp->enemyMove();
  return tmp->lose();
}

bool TestPlayerAttack() {
  Playground *tmp = get();

  // row 1 -- three flutes
  Flute flute;
  Cash::add(Flute().getCost());
  tmp->playerInsert(0, 0, &flute);
  Cash::add(Flute().getCost());
  tmp->playerInsert(0, 1, &flute);
  Cash::add(Flute().getCost());
  tmp->playerInsert(0, 2, &flute);
  // row 2 -- empty
  // row 3 -- 1 trumpet (should do damage on 3 rows)
  Trumpet trumpet;
  Cash::add(trumpet.getCost());
  tmp->playerInsert(2, 0, &trumpet);
  // row 4 -- 1 drum (should do damage for 3 more columns)
  Drum drum;
  Cash::add(drum.getCost());
  tmp->playerInsert(3, 0, &drum);
  // row 5 -- 1 violin (should slow down the first enemy)
  Violin violin;
  Cash::add(violin.getCost());
  tmp->playerInsert(4, 0, &violin);

  u32 i = 0;
  tmp->playerAttack(i++);
  if (MusicInstruments::damages[3][1] != music::New(THREE_C)->attack())
    return false;

  // check the other instruments
  for (; i < COLUMNS; i++)
    tmp->playerAttack(i);
  if (MusicInstruments::damages[0][0] != Flute().MusicInstruments::attack() * 3)
    return false;
  if (MusicInstruments::damages[1][0] != Trumpet().MusicInstruments::attack() ||
      MusicInstruments::damages[2][0] != Trumpet().MusicInstruments::attack() ||
      MusicInstruments::damages[3][0] != Trumpet().MusicInstruments::attack())
    return false;
  if (MusicInstruments::damages[3][1] != 0)
    return false;
  if (MusicInstruments::damages[4] == 0)
    return false;
  return true;
}

bool TestEnemyAttack() {
  Playground *tmp = get();
  Flute flute;
  Cash::add(flute.getCost());
  tmp->playerInsert(0, 0, &flute);
  tmp->enemyInsert(0, 100);
  for (u32 i = 0; i < 60; i++)
    tmp->enemyMove();
  for (u32 i = 0; i < 100; i++)
    tmp->enemyAttack(0);
  Cash::add(flute.getCost());
  return tmp->playerInsert(0, 0, &flute);
}

#include "Manifestante.h"

Manifestante::Manifestante(int x, int y)
{
  m_x = x;
  m_y = y;
}

void Manifestante::update()
{
  // Incremento en el eje X para que el manifestante se mueva.
  // Utilizamos un incremento decimal para regular la velocidad del
  // manifestante. Con "m_x++" se movería con un incremento de 1 más rápidamente.
  m_x = m_x + 0.4;

  if (m_x >= 119)
  {
    // Cuando el manifestante llegue al límite lo volvemos a subir
    // a una posición en y al azar.
    // El alto de la pantalla va de 0 a 39 (ALTO = 39).
    // En 0 y en 39 tenemos los bordes de la pantalla, por lo que el
    // manifestante tendría que aparecer entre el 1 y el 38.
    m_y = rand() % 38 + 1; // Valor aleatorio entre 1 y 38
    m_x = 1;
  }
}

void Manifestante::draw()
{
  /******************\ 
  Dibujo del manifestante
        0  {¡#!}
       - -   |  
       / \      
  \******************/ 
 mvprintw(m_y, m_x, R"( 0  {¡#!})");
 mvprintw(m_y + 1, m_x, R"(- -   |  )");
 mvprintw(m_y + 2, m_x, R"(/ \      )");
}
void Manifestante::colision(Estudiante &rEstudiante);
{
  // Verificamos la colisión. 
  // Si se cumplen estas condiciones quiere decir que el estudiante entró
  // en contacto con el bounding box (rectángulo) del estudiante (COLISION).
  if(m_x >= rEstudiante.getX() && m_x <= rEstudiante.getX() + 4 && m_y >= rEstudiante.getY() && m_y <= rEstudiante.getY() + 2)
  {
    // Si hay colisión disminuimos las vidas del estudiante.
    rEstudiante.setVidas(rEstudiante.getVidas() - 1);

    // Volvemos a colocar el manifestante arriba de todo.
    m_x = rand() % 118 + 1;
    m_y = 1;
  }
}

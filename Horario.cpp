/*
 * 	Universidad de La Frontera
 *	Ingenieria Civil Telematica
 *	
 *	IIE-344-1 ESTRUCURA DE DATOS Y ALGORITMOS
 *	
 *	Tarea 1
 *
 *	Autor 1: Pedro Paulo Enrique Muñoz Gatica 
 *	Autor 2: Benjamin Eduardo Lagos Roa
 *
 *	Fecha: 08/12/2020
 *
 * 	Proyecto Horario Personal: HORARIO VIRTUAL
 *
 * El proyecto consiste en solventar la falta de un horario personal universitario el cual almacena 
 * los horarios fijos ingresados uno a uno por el usuario, esto incluyendo el nombre del profesor que rinde la clase, 
 * el link de ingreso a clases y la hora de inicio y termino de la clase. Esto con el fin ademas de sobrellevar este
 * periodo de pandemia el cual exige a los alumnos una organizacion personal completa y  una mayor responsabilidad
 * con sus estudios.
 * 
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>

//Estructuras que sirven a lo largo del codigo

struct Ramo
{
	char nombre_ramo[30];
	char nombre_profe[30];
	char link_clase[120];
};

struct Clase
{
	int hora_inicio;
	int minuto_inicio;
	int hora_termino;
	int minuto_termino;
};

int seleccion_ramo(int cant_ramos, Ramo Ramos[8]);

int main()
{

	//Definicion de variables, se usaran en todo el programa.

	Clase Horarios_clases[7][12];
	Ramo Ramos[8];
	char semana[20][22] = {{"Semanas/Semana#1.txt"}, {"Semanas/Semana#2.txt"}, {"Semanas/Semana#3.txt"}, {"Semanas/Semana#4.txt"}, {"Semanas/Semana#5.txt"}, {"Semanas/Semana#6.txt"}, {"Semanas/Semana#7.txt"}, {"Semanas/Semana#8.txt"}, {"Semanas/Semana#9.txt"}, {"Semanas/Semana#10.txt"}, {"Semanas/Semana#11.txt"}, {"Semanas/Semana#12.txt"}, {"Semanas/Semana#13.txt"}, {"Semanas/Semana#14.txt"}, {"Semanas/Semana#15.txt"}, {"Semanas/Semana#16.txt"}, {"Semanas/Semana#17.txt"}, {"Semanas/Semana#18.txt"}, {"Semanas/Semana#19.txt"}, {"Semanas/Semana#20.txt"}};
	int cant_clases[7];
	char dia_semana[7][12] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
	char posicion[12][10] = {"primera", "segunda", "tercera", "cuarta", "quinta", "sexta", "septima", "octava", "novena", "decima", "undecima", "duodecima"};
	int opcion_selec = 0;
	int ramo_seleccionado[7][8];
	int cant_semanas, cant_ramos;
	int semana_evento, dia_evento, hora_evento, minuto_evento;
	char descripcion_evento[100];

	printf(" **=====================================**\n");
	printf(" ||\t      Bienvenido a tu\t\t||\n ||\tH O R A R I O  V I R T U A L\t||\n");
	printf(" **=====================================**\n\n");

	while (opcion_selec != 3)
	{ //Se realiza un while en caso de ingresar una entrada incorrecta.

		printf(" || Que desea realizar?\n\n");
		printf(" 1. Crear un horario fijo de estudio.\n");
		printf(" 2. Agendar evento o recordatorio.\n");
		printf(" 3. Salir del programa.\n");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion_selec);
		system("cls");

		switch (opcion_selec)
		{ //Switch para la opcion seleccionada.

		case 1: //Caso 1: Crear un horario fijo de estudios el cual se mantendrá según la cantidad de semanas que ingrese el usuario.
		{
			int c = 0;
			FILE *f = fopen("trash.txt", "r");
			if (f != NULL)
			{
				printf("Usted ya tiene un horario fijo creado, quiere sobreescribir el horario fijo anterior?\n");
				printf(" 1.Si\n");
				printf(" 2.No\n");
				scanf("%d", &c);
				if (c == 2)
				{
					system("cls");
					break;
				}
			}
			fclose(f);
		}
			printf(" || Cuantas semanas estara impartiendo esta rutina de estudios?\n");
			printf("\nIngrese la cantidad de semanas: ");
			scanf("%d", &cant_semanas);
			system("cls");

			printf(" || A continuacion ingrese los datos solicitados:\n");
			printf("\nIngrese la cantidad de ramos a rendir en este periodo (maximo 8 ramos): ");
			scanf("%d", &cant_ramos);
			system("cls");

			for (int i = 0; i < cant_ramos; i++)
			{ //Solicitud de los datos de cada ramo para guardarlos
				//y posteriormente usarlos en el código.
				printf(" || RAMO %d\n", i + 1);
				fflush(stdin);
				printf("\nIngrese el nombre del RAMO %d: ", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_ramo);
				fflush(stdin);
				printf("\nIngrese el nombre del profesor que rinde el RAMO %d: ", i + 1);
				scanf("%[^\n]", Ramos[i].nombre_profe);
				fflush(stdin);
				printf("\nPegue el link de ingreso a la clase del RAMO %d: ", i + 1);
				scanf("%[^\n]", Ramos[i].link_clase);
				system("cls");
			}

			int a;
			for (int i = 0; i <= 4; i++)
			{ //for que repite el ingreso de datos diarios la cantidad de dias de la semana.

				do
				{
					a = 0;
					printf(" || DIA %s\n", dia_semana[i]);
					printf("\nIngrese la cantidad de clases a las que debe asistir el DIA %s: ", dia_semana[i]);
					scanf("%d", &cant_clases[i]);
					system("cls");

					for (int j = 0; j < cant_clases[i]; j++)
					{ //for que repite el ingreso de datos de cada clase asistida
						//segun la cantidad de clases diarias que tenga el usuario.
						int b;

						printf(" || DIA %s\n", dia_semana[i]);
						printf("\nIngrese la %s clase del DIA %s: ", posicion[j], dia_semana[i]); //Se especifica el orden de entrada para no hacer
						ramo_seleccionado[i][j] = seleccion_ramo(cant_ramos, Ramos);			  //tan complejo el ingreso de datos al .txt.

						do
						{
							b = 0;
							if (j != 0)
							{ //Se muestra por pantalla los horarios previamente ingresados para una mejor compresion de como se guardara el archivo.
								printf("\n\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
								for (int k = 0; k < j; k++)
								{
									printf(" [%d] %s (%d:%d - %d:%d)\n", k + 1, Ramos[ramo_seleccionado[i][k]].nombre_ramo, Horarios_clases[i][k].hora_inicio, Horarios_clases[i][k].minuto_inicio, Horarios_clases[i][k].hora_termino, Horarios_clases[i][k].minuto_termino);
								}
							}

							printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); //Ingreso de las horas de inicio y termino de cada una de las clases de un dia en especifico(esto se hace igual para todos los dias).
							printf("\n || A continuacion ingrese la hora de INICIO y TERMINO de '%s' (use formato 24hrs).\n", Ramos[ramo_seleccionado[i][j]].nombre_ramo);

							printf("\nIngrese la hora de inicio en formato 'HH:MM': ");
							scanf("%d:%d", &Horarios_clases[i][j].hora_inicio, &Horarios_clases[i][j].minuto_inicio);

							printf("\nIngrese la hora de termino en formato 'HH:MM': ");
							scanf("%d:%d", &Horarios_clases[i][j].hora_termino, &Horarios_clases[i][j].minuto_termino);
							system("cls");
							for (int m = 0; m < cant_clases[i]; m++)
							{
								if (j == m)
								{
									continue;
								}
								if (((Horarios_clases[i][j].hora_inicio > Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].hora_inicio < Horarios_clases[i][m].hora_termino)) || ((Horarios_clases[i][j].hora_termino > Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].hora_termino < Horarios_clases[i][m].hora_termino)) || ((Horarios_clases[i][j].hora_inicio == Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].minuto_inicio >= Horarios_clases[i][m].minuto_inicio)) || ((Horarios_clases[i][j].hora_termino == Horarios_clases[i][m].hora_inicio) && (Horarios_clases[i][j].minuto_termino >= Horarios_clases[i][m].minuto_inicio)) || ((Horarios_clases[i][j].hora_inicio == Horarios_clases[i][m].hora_termino) && (Horarios_clases[i][j].minuto_inicio <= Horarios_clases[i][m].minuto_termino)) || ((Horarios_clases[i][j].hora_termino == Horarios_clases[i][m].hora_termino) && (Horarios_clases[i][j].minuto_termino <= Horarios_clases[i][m].minuto_termino)))
								{ //Este if corrobora que ninguno de los horarios anteriormente ingresados irrumpan con el actual, en el caso de que irrumpan se consulta al usuario si desea guardar igualmente el horario.
									printf("Este horario ingresado irrumpe con el horario: %s (%d:%d ~ %d:%d)\n", Ramos[ramo_seleccionado[i][m]].nombre_ramo, Horarios_clases[i][m].hora_inicio, Horarios_clases[i][m].minuto_inicio, Horarios_clases[i][m].hora_termino, Horarios_clases[i][m].minuto_termino);
									printf("\nDesea continuar?\n");
									printf(" 1. Si\n");
									printf(" 2. No (ingresar un nuevo horario)\n");
									printf("\nIngrese una opcion: ");
									scanf("%d", &b);
									system("cls");
									break;
								}
							}
						} while (b == 2); //Este do while es en el caso de querer editar el horario ingresado de la ultima clase.
					}

					printf(" || HORARIO DIA %s\n\n", dia_semana[i]);
					printf("El horario del DIA %s quedara de la siguiente manera:\n", dia_semana[i]); //Se muestra la vista previa del ingreso de horarios diarios.
					printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
					for (int j = 0; j < cant_clases[i]; j++)
					{
						//Con este if revisaremos la escritura de los minutos.

						if ((Horarios_clases[i][j].minuto_inicio == 0 && Horarios_clases[i][j].minuto_termino == 0) || (Horarios_clases[i][j].minuto_inicio < 10 && Horarios_clases[i][j].minuto_termino < 10) || (Horarios_clases[i][j].minuto_inicio < 10 && Horarios_clases[i][j].minuto_termino == 0) || (Horarios_clases[i][j].minuto_inicio == 0 && Horarios_clases[i][j].minuto_termino < 10))
						{
							printf(" [%d] %s (%d:0%d - %d:0%d)\n", j + 1, Ramos[ramo_seleccionado[i][j]].nombre_ramo, Horarios_clases[i][j].hora_inicio, Horarios_clases[i][j].minuto_inicio, Horarios_clases[i][j].hora_termino, Horarios_clases[i][j].minuto_termino);
						}
						else
						{
							printf(" [%d] %s (%d:%d - %d:%d)\n", j + 1, Ramos[ramo_seleccionado[i][j]].nombre_ramo, Horarios_clases[i][j].hora_inicio, Horarios_clases[i][j].minuto_inicio, Horarios_clases[i][j].hora_termino, Horarios_clases[i][j].minuto_termino);
						}
					}
					printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					//Se consulta nuevamente por si se observa algun error en lo ingresado.

					printf("\nEs correcta la informacion?\n\n");
					printf(" 1. Si\n");
					printf(" 2. No (se realizara nuevamente)\n");
					printf("\nIngrese una opcion: ");
					scanf("%d", &a);
					system("cls");

				} while (a == 2); //Este do while es en el caso de que el usuario quiera ingresar desde 0 los horarios diarios.
			}

			for (int i = 0; i < cant_semanas; i++)
			{ //Pega los datos en los txt creados con el for en un formato especifico.

				FILE *arch = fopen(semana[i], "w");
				fprintf(arch, "Ramos:\n\n");

				for (int j = 0; j < cant_ramos; j++)
				{
					fprintf(arch, "(%d) %s / %s\n", j + 1, Ramos[j].nombre_ramo, Ramos[j].nombre_profe);
				}

				fprintf(arch, "\n~*~* HORARIOS Y EVENTOS *~*~\n\n");
				for (int k = 0; k <= 4; k++)
				{

					if (cant_clases[k] == 0)
					{
						continue;
					}

					fprintf(arch, "[HORARIOS] %s:\n", dia_semana[k]);
					for (int j = 0; j < cant_clases[k]; j++)
					{
						fprintf(arch, "[%d] (%d:%d ~ %d:%d) - %s - %s\n", j + 1, Horarios_clases[k][j].hora_inicio, Horarios_clases[k][j].minuto_inicio, Horarios_clases[k][j].hora_termino, Horarios_clases[k][j].minuto_termino, Ramos[ramo_seleccionado[k][j]].nombre_ramo, Ramos[ramo_seleccionado[k][j]].link_clase);
					}
					fprintf(arch, "[EVENTOS] %s:\n", dia_semana[k]);
					if (k != 4)
					{
						fprintf(arch, "\n----------------------------------------------\n");
					}
				}
				fclose(arch);
			}

			{
				FILE *f = fopen("trash.txt", "w"); //Generamos un archivo trash que no tiene como objetivo ser abierto por el usuario, solamente con el fin de guardar datos que optimicen la funcionalidad del programa.
				fprintf(f, "%d %d\n", cant_semanas, cant_ramos);
				for (int i = 0; i <= 4; i++)
				{
					fprintf(f, "%d\n", cant_clases[i]);
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", ramo_seleccionado[i][j]);
					}
				}
				printf("%d\n", cant_clases[0]);
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].hora_inicio);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].minuto_inicio);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].hora_termino);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%d\n", Horarios_clases[i][j].minuto_termino);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%s\n", Ramos[ramo_seleccionado[i][j]].nombre_ramo);
					}
				}
				for (int i = 0; i <= 4; i++)
				{
					for (int j = 0; j < cant_clases[i]; j++)
					{
						fprintf(f, "%s\n", Ramos[ramo_seleccionado[i][j]].link_clase);
					}
				}

				fclose(f);
			}

			break;

		case 2:
		{ //Caso 2: Crear un evento en una semana, dia y hora en especifico una vez realizado el horario fijo (caso 1).
			FILE *f0 = fopen("trash.txt", "r");
			if (f0 == NULL)
			{ //Se corrobora que el archivo trash esta creado, en el caso de que no lo esté, informar al usuario que todavia no tiene creado un Horario Fijo y enviarlo al menu principal.
				printf("Todavia no ha creado un horario fijo.\n");
				system("pause");
				system("cls");
				break;
			}
			fscanf(f0, "%d %d\n", &cant_semanas, &cant_ramos); //Se leen los datos dentro del trash para ser utilizados en el programa.
			for (int i = 0; i <= 4; i++)
			{
				fscanf(f0, "%d\n", &cant_clases[i]);
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j < cant_clases[i]; j++)
				{
					fscanf(f0, "%d\n", &ramo_seleccionado[i][j]);
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j < cant_clases[i]; j++)
				{
					fscanf(f0, "%d\n", &Horarios_clases[i][j].hora_inicio);
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j < cant_clases[i]; j++)
				{
					fscanf(f0, "%d\n", &Horarios_clases[i][j].minuto_inicio);
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j < cant_clases[i]; j++)
				{
					fscanf(f0, "%d\n", &Horarios_clases[i][j].hora_termino);
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j < cant_clases[i]; j++)
				{
					fscanf(f0, "%d\n", &Horarios_clases[i][j].minuto_termino);
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j < cant_clases[i]; j++)
				{
					fscanf(f0, "%[^\n]\n", Ramos[ramo_seleccionado[i][j]].nombre_ramo);
				}
			}
			for (int i = 0; i <= 4; i++)
			{
				for (int j = 0; j < cant_clases[i]; j++)
				{
					fscanf(f0, "%[^\n]\n", Ramos[ramo_seleccionado[i][j]].link_clase);
				}
			}
			fclose(f0);
		}
			int d;

			printf("Ingrese la semana en la que quiere añadir un evento: "); //Inicio de el ingreso de datos para crear el evento.
			scanf("%d", &semana_evento);
			{

				FILE *f;
				f = fopen(semana[semana_evento - 1], "r+");
				if (f == NULL)
				{ //Se corrobora que la semana ingresada exista, de no ser asi, informar al usuario que no existe y enviarlo al menu anterior.
					printf("ERROR!! La semana seleccionada no existe\n");
					system("pause");
					system("cls");
					fclose(f);
					break;
				}
				fclose(f);
			}

			printf("Los dias son los siguientes:\n\n");
			printf("1. Lunes\n2. Martes\n3. Miercoles\n4. Jueves\n");
			printf("5. Viernes\n6. Sabado\n7. Domingo\n");
			printf("\nIngrese el dia en el que quiere ingresar el evento: ");
			scanf("%d", &dia_evento);

			do
			{
				d = 0;

				printf("\n\nIngrese hora del evento: ");
				scanf("%d:%d", &hora_evento, &minuto_evento);

				if (!(dia_evento == 6 || dia_evento == 7))
				{ //Ya que los dias sabados y domingos no son parte del horario regular de un estudiante se dejan apartados, ademas, dado que los datos en el trash solo guardan informacion de lunes a viernes daría error al inlcuirlos aqui.

					for (int k = 0; k < cant_clases[dia_evento - 1]; k++)
					{

						if ((hora_evento > Horarios_clases[dia_evento - 1][k].hora_inicio) && (hora_evento < Horarios_clases[dia_evento - 1][k].hora_termino))
						{ //Este if corrobora que ninguno de los horarios anteriormente ingresados en el horario fijo irrumpan con el evento, en el caso de que irrumpan se consulta al usuario si desea guardar igualmente el evento.

							printf("\nEl evento ingresado irrumpe con el ramo: %s (%d:%d ~ %d:%d)\n", Ramos[ramo_seleccionado[dia_evento - 1][k]].nombre_ramo, Horarios_clases[dia_evento - 1][k].hora_inicio, Horarios_clases[dia_evento - 1][k].minuto_inicio, Horarios_clases[dia_evento - 1][k].hora_termino, Horarios_clases[dia_evento - 1][k].minuto_termino);
							printf("Desea continuar?\n");
							printf(" 1. Si\n");
							printf(" 2. No (Ingresar otra hora y minuto del evento)\n");
							scanf("%d", &d);
							break;
						}
						else if ((hora_evento == Horarios_clases[dia_evento - 1][k].hora_inicio) && (minuto_evento >= Horarios_clases[dia_evento - 1][k].minuto_inicio))
						{

							printf("\nEl evento ingresado irrumpe con el ramo: %s (%d:%d ~ %d:%d)\n", Ramos[ramo_seleccionado[dia_evento - 1][k]].nombre_ramo, Horarios_clases[dia_evento - 1][k].hora_inicio, Horarios_clases[dia_evento - 1][k].minuto_inicio, Horarios_clases[dia_evento - 1][k].hora_termino, Horarios_clases[dia_evento - 1][k].minuto_termino);
							printf("Desea continuar?\n");
							printf(" 1. Si\n");
							printf(" 2. No (Ingresar otra hora y minuto del evento)\n");
							scanf("%d", &d);
							break;
						}
						else if ((hora_evento == Horarios_clases[dia_evento - 1][k].hora_termino) && (minuto_evento <= Horarios_clases[dia_evento - 1][k].minuto_termino))
						{

							printf("\nEl evento ingresado irrumpe con el ramo: %s (%d:%d ~ %d:%d)\n", Ramos[ramo_seleccionado[dia_evento - 1][k]].nombre_ramo, Horarios_clases[dia_evento - 1][k].hora_inicio, Horarios_clases[dia_evento - 1][k].minuto_inicio, Horarios_clases[dia_evento - 1][k].hora_termino, Horarios_clases[dia_evento - 1][k].minuto_termino);
							printf("Desea continuar?\n");
							printf(" 1. Si\n");
							printf(" 2. No (Ingresar otra hora y minuto del evento)\n");
							scanf("%d", &d);
							break;
						}
					}
				}
			} while (d == 2); //Este es el while que envia al usuario a ingresar nuevamente la hora del evento.
			{
				printf("Ingrese la descripcion del evento: ");
				fflush(stdin);
				scanf("%[^\n]", descripcion_evento);
				system("cls");

				//Se realizan 2 contadores para distintos txt (uno reemplazara a otro luego de copiar la informacion y añadir el nuevo evento de forma ordenada) los cuales contaran el numero de
				//lineas que tiene cada uno, esto con el fin de verificar cuando uno de los dias no tiene generado un horario fijo y asi añadir igualmente los eventos de forma agrupada por dia.

				int cont1 = 0;
				int cont2 = 1;

				char aux1[150];
				char indicador1[11] = "[EVENTOS] ";
				char dos_puntos[3] = ":\n";
				strcat(indicador1, dia_semana[dia_evento - 1]);
				strcat(indicador1, dos_puntos);
				FILE *f = fopen(semana[semana_evento - 1], "r+");
				FILE *f1 = fopen("Semanas/Semana_Auxiliar.txt", "a+");
				while (!feof(f))
				{ //Se realiza el conteo de el primer archivo y se copia la informacion del archivo original.
					fgets(aux1, 150, f);
					cont1++;
				}
				fseek(f, 0, SEEK_SET);
				while (fgets(aux1, 150, f) != NULL)
				{ //Se realiza el conteo del archivo auxiliar y se pega lo del primer archivo en el archivo auxiliar.
					cont2++;
					fprintf(f1, "%s", aux1);
					if (strcmp(aux1, indicador1) == 0)
					{
						break;
					}
				}
				if (cont1 == cont2)
				{ //En el caso de que el dia especificado no tenga una seccion en el archivo se crea una con el nombre del dia y se guarda el evento en esta nueva seccion.
					fprintf(f1, "%s", indicador1);
					fprintf(f1, "- (%d:%d) - %s\n\n", hora_evento, minuto_evento, descripcion_evento);
					fprintf(f1, "----------------------------------------------\n");
				}
				else
				{ //En el caso de que el dia especificado tenga una seccion en el archivo se añade el evento y ademas el resto de lo almacenado en el archivo original.
					fprintf(f1, "- (%d:%d) - %s\n", hora_evento, minuto_evento, descripcion_evento);

					while (fgets(aux1, 150, f) != NULL)
					{
						fprintf(f1, "%s", aux1);
					}
				}
				fclose(f1);
				fclose(f);
			}
			remove(semana[semana_evento - 1]);								  //Se elimina el archivo original.
			rename("Semanas/Semana_Auxiliar.txt", semana[semana_evento - 1]); //Se renombra el archivo auxiliar por el del archivo original.
			system("cls");

			break;

		case 3: //Caso 3: Salir del programa.
			return 0;
			break;

		default:
			if ((opcion_selec < 1) || (opcion_selec > 3))
			{ //Entrega un mensaje de error en caso de una entrada erronea.
				system("cls");
				printf(" **=====================================**\n");
				printf(" ||\t      Bienvenido a tu\t\t||\n ||\tH O R A R I O  V I R T U A L\t||\n");
				printf(" **=====================================**\n\n");

				printf("ERROR!! Ingrese una opcion valida.\n\n");
			}

			break;
		}
	}

	return 0;
}

int seleccion_ramo(int cant_ramos, Ramo Ramos[8])
{
	int a;

	for (int i = 0; i < cant_ramos; i++)
	{
		printf("\n %d. %s\n", i + 1, Ramos[i].nombre_ramo);
	}

	printf("\nIngrese la opcion de su ramo: ");
	scanf("%d", &a);

	while ((a <= 0) || (a > (cant_ramos + 1)))
	{
		printf("ERROR!! Ingrese una opcion valida: ");
		scanf("%d", &a);
		system("cls");
	}
	a = a - 1;
	return a;
}

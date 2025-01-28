        #include "queue.h"
        #include <stdlib.h>
        #include <stdio.h>

        #define MinQueueSize ( 5 )

        struct QueueRecord
        {
            int Capacity;
            int Front;
            int Rear;
            int Size;
            ElementType *Array;
        };


/* START: fig3_58.txt *111/
        int
        IsEmpty( Queue Q )
        {
            return Q->Size == 0;
        }
/* END */

        int
        IsFull( Queue Q )
        {
            return Q->Size == Q->Capacity;
        }

        Queue
        
CreateQueue( int MaxElements )
{
    Queue Q;

/* 1*/      if( MaxElements < MinQueueSize )
/* 2*/          printf( "Queue size is too small" );

/* 3*/      Q = malloc( sizeof( struct QueueRecord ) );
/* 4*/      if( Q == NULL )
/* 5*/          printf( "Out of space!!!" );

/* 6*/      Q->Array = malloc( sizeof( ElementType ) * MaxElements );
/* 7*/      if( Q->Array == NULL )
/* 8*/          printf( "Out of space!!!" );
/* 9*/      Q->Capacity = MaxElements;
/*10*/      MakeEmpty( Q );

/*11*/      return Q;
}

/* START: fig3_59.txt */
        void
        MakeEmpty( Queue Q )
        {
            Q->Size = 0;
            Q->Front = 0;
            Q->Rear = 0;
        }
/* END */

        void
        DisposeQueue( Queue Q )
        {
            if( Q != NULL )
            {
                free( Q->Array );
                free( Q );
            }
        }

/* START: fig3_60.txt */

        static int
        Succ( int Value, Queue Q )
        {
            if( ++Value == Q->Capacity )
                Value = 0;
            return Value;
        }

        void
        Enqueue( ElementType X, Queue Q )
        {
            if( IsFull( Q ) )
                printf( "Full queue" );
            else
            {
                Q->Size++;
                Q->Array[ Q->Rear ] = X;
                Q->Rear = Succ( Q->Rear, Q );
            }
        }
/* END */




        ElementType
        Front( Queue Q )
        {
            if( !IsEmpty( Q ) )
                return Q->Array[ Q->Front ];
            printf( "Empty queue" );
            return 0;  /* Return value used to avoid warning */
        }



int Dequeue(Queue Q)
{
    if(IsEmpty(Q))  {printf("Empty Queue"); return 0;}
    int value;
    value=Q->Array[Q->Front];
    Q->Front=Succ(Q->Front,Q);
    (Q->Size)--;
    return value;
}











        ElementType
        FrontAndDequeue( Queue Q )
        {
            ElementType X = 0;

            if( IsEmpty( Q ) )
                printf( "Empty queue" );
            else
            {
                Q->Size--;
                X = Q->Array[ Q->Front ];
                Q->Front = Succ( Q->Front, Q );
            }
            return X;
        }


void PrintQueue(Queue Q)
{
    int i;
    for(i=Q->Front;i<Q->Rear;i=Succ(i,Q))
    {
        printf("%d\n",Q->Array[i]);
    }
}







int main(void)
{
    Queue Q;
    Q=CreateQueue(50);
    int i;
    for(i=0;i<49;i++)
    {
        Enqueue(i,Q);
    }
    //Dequeue(Q);
    PrintQueue(Q);
}
 class Consumer extends Thread {
    private Queue q;
 
   public void run() {
      while (true) {
          /*+1*/synchronized (q) {/*-1*/
            Customer c = q.front();
            q.leave();
          };
          ... process customer ...
        }
      }
   }
 }

 class Producer extends Thread {
    private Queue q;
 
   public void run() {
      while (true) {
        Customer c = fetchData();
        /*+1*/synchronized (line1) {/*-1*/
           q.enter(c);
        }
     }
 }
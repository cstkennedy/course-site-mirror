public interface AudioClip { 
    /** 
     * Starts playing this audio clip. Each time this method is called,  
     * the clip is restarted from the beginning.  
     */ 
    void play(); 
 
    /** 
     * Starts playing this audio clip in a loop.  
     */ 
    void loop(); 
 
    /** 
     * Stops playing this audio clip.  
     */ 
    void stop(); 
} 

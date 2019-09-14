namespace transformationRate {
   static float rotation = 1.0f;
   static float translation = 1.0f;
   static float scaling = 1.0f;

   static void increaseRotationRate() {
      (rotation < 50.0f) ? rotation += 2.0f : rotation;
   }
   static void increaseTranslationRate() {
      (translation < 100.0f) ? translation += 10.0f : translation;
   }
   static void increaseScalingRate() {
      (scaling < 10.0f) ? scaling += 1.5f : scaling;
   }
}

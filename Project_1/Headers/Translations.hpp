enum class Direction {
   X,
   Y,
   Z
};
namespace transformationRate {
   static glm::vec3 rotationAngle(0.0f, 0.0f, 0.0f);
   static glm::vec3 translationVec(0.0f, 0.0f, 0.0f);
   static glm::vec3 scalingVec(0.0f, 0.0f, 0.0f);

   static void increaseRotationRate(Direction direction) {
      switch (direction){
         case (Direction::X):
            rotationAngle.x += 1.1f;
         break;
         case (Direction::Y):
            rotationAngle.y += 1.1f;
         break;
         case (Direction::Z):
            rotationAngle.z += 1.1f;
         break;
      }
   }
   static void decreaseRotationRate(Direction direction) {
      switch (direction){
         case (Direction::X):
            rotationAngle.x -= 1.1f;
         break;
         case (Direction::Y):
            rotationAngle.y -= 1.1f;
         break;
         case (Direction::Z):
            rotationAngle.z -= 1.1f;
         break;
      }
   }
}

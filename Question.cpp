#include "Question.h"

Question::Question(const std::string& q, const std::vector<std::string>& opts, int correct)
    : questionText(q), options(opts), correctOption(correct) {}

std::vector<Question> Question::getQuestions() {
    return {
        Question("What is the minimum age requirement to apply for a motorcycle license in Nepal?", {"18 years", "16 years", "20 years", "21 years"}, 0),
        Question("Which side of the road should you drive on in Nepal?", {"Left", "Right", "Center", "Any side"}, 0),
        Question("What is the maximum speed limit for motorcycles in urban areas in Nepal?", {"40 km/h", "30 km/h", "50 km/h", "60 km/h"}, 0),
        Question("When should you use the horn on your motorcycle?", {"To warn others of danger", "To greet friends", "To signal frustration", "To startle pedestrians"}, 0),
        Question("What should you do when approaching a pedestrian crossing?", {"Slow down and give way to pedestrians", "Accelerate and cross quickly", "Sound the horn and pass", "Ignore pedestrians"}, 0),
        Question("What does a red traffic light indicate?", {"Stop", "Proceed with caution", "Go", "Yield"}, 0),
        Question("What safety gear is mandatory for motorcycle riders in Nepal?", {"Helmet", "Gloves", "Boots", "Elbow pads"}, 0),
        Question("What is the legal blood alcohol concentration (BAC) limit for motorcycle riders in Nepal?", {"0.00%", "0.05%", "0.08%", "0.10%"}, 0),
        Question("What should you do if your motorcycle skids?", {"Steer in the direction of the skid", "Accelerate to regain control", "Apply the brakes hard", "Jump off the motorcycle"}, 0),
        Question("What does a yellow traffic light indicate?", {"Prepare to stop", "Stop immediately", "Proceed with caution", "Speed up to pass quickly"}, 0),
        Question("When is it permissible to overtake another vehicle on the left?", {"When the vehicle in front is turning right", "When there is a slow-moving vehicle", "In a one-way street", "When there is a queue of cars"}, 0),
        Question("What is the meaning of a triangular road sign with a red border?", {"Warning of a hazard", "Mandatory instruction", "Informative message", "Directional guidance"}, 0),
        Question("What should you do if an emergency vehicle is approaching with sirens on?", {"Pull over to the side and stop", "Continue driving at the same speed", "Speed up to avoid obstructing it", "Ignore and continue"}, 0),
        Question("What is the purpose of a roundabout?", {"To manage traffic flow at intersections", "To speed up traffic", "To allow for overtaking", "To provide parking space"}, 0),
        Question("What does a blue road sign with a white 'P' indicate?", {"Parking area", "Prohibited area", "Pedestrian crossing", "Police station"}, 0)
    };
}

